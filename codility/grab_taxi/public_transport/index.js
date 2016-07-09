'use strict';

console.log(
(function solution (A){
	//no point considering 30days ticket, if in the end lowest price exceeds 25 just return 25
	let result = 0;
	let sizeOfA = A.length;
	if (sizeOfA === 0) return 0;
	let dividers = 0;
	//this is a graph, A_i is connected to A_i+1 via edge cost 2 and to some A_j cost 7 
	//if (A_j-A_i is at least 6 
	//or it is the last element)
	//need to find a minimal path from A_0 to A_last

	let graph = Array.from({length:sizeOfA}, () => Array.from({length: sizeOfA}, () => 10000));
	let divided = true;
	for(let i = 0; i < sizeOfA-1; i++){
		if (A[i+1] - A[i] < 7){
			graph[i][i+1] = divided ? 4:2;
			divided = false;
		}
		else {
			divided = true;
			graph[i][i+1] = 0;
		}
	}
	for(let i = 0; i < sizeOfA - 2; i++){
		let j = i + 2;
		while(A[j]-A[i] < 7){
			graph[i][j] = 7;
			j++;
		}
	}
	result = findOptimalPath(graph, A[0]).dist;
	return (result < 25) ? result : 25;
})([1,2,3,4,5,6,7,13,24,25,26,27])
)
//simple Dijkstra implementation
function findOptimalPath(graph, source){
	let vertexSet = Array.from({length:graph.length}, (v, i) => {
		let dist = 10000;
		let prev = undefined;
		return {
			dist: dist,
			prev: prev,
			index: i,
			poped: false
		};
	});
	vertexSet[0].dist = 0;
	while(true){
		let cur = minDistFromSelected();
		vertexSet[cur].poped = true;
		if (cur === (graph.length - 1)) {
			return vertexSet[cur];
		}
		for(let i = 0;i < graph[cur].length; i++){
			if (graph[cur][i] < 10000){ //neighbours
				let alt = vertexSet[cur].dist + graph[cur][i];
				if (alt < vertexSet[i].dist){
					vertexSet[i].dist = alt;
					vertexSet[i].prev = vertexSet[cur];
				}
			}
		}
	}

	function minDistFromSelected(){
		let dist = 10000;
		let selected = 0;
		for(let i = 0; i < vertexSet.length; i++){
			if (!vertexSet[i].poped && vertexSet[i].dist < dist) { selected = i; dist = vertexSet[i].dist }
		}
		return selected;
	}
}