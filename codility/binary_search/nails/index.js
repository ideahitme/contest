'use strict';

function solution(A, B, C){
	let begin = 1;
	let end = find_endpoint(B);
	C = C.map((a, index) => {return { val: a, index: index} });
	C = C.sort((a,b) => a.val-b.val);
	C = cleanUp(C);
	console.log(C);
	let marked = markItDown(C);
	let res = -1;
	for(let i = 0; i < A.length; i++){
		let min_depth = find_nail_in_range(marked, A[i], B[i]);
		if (min_depth > res) res = min_depth;
	}
	if (res > 60000) return -1;
	return res + 1;
}

function cleanUp(C){
	if (C.length < 2) return C;
	let processed = [];
	let prev = C[0];
	let i = 1;
	while(i < C.length){
		if (prev.val === C[i].val){
			if (C[i].index < prev.index){
				prev = C[i];
				C[i-1] = undefined;
			}
			else{
				C[i] = undefined;
			}
		}
		else{
			prev = C[i];
		}
		i++;
	}
	for(let i = 0; i < C.length; i++){
		if (C[i]) processed.push(C[i]);
	}
	return processed;
}

function markItDown(C){
	let result = Array.from({length:21}, () => -1);
	let i = 0;
	let j = 0;
	while(i < C.length){
		while(j <= C[i].val){
			result[j] = C[i];
			j++;
		}
		i++;
	}
	return result;
}
//C sorted alr
function find_nail_in_range(marked, a, b){
	let i = a;
	let nail_index = 60001;
	while(i < b+1){
		if (marked[i] === -1) break;

		let next_nail = marked[i].val;
		if (next_nail <= b){
			if (marked[i].index < nail_index) nail_index = marked[i].index;
		}
		else break;
		try {
			i = marked[marked[i].val+1].val;
		} catch(err){ break; }
	}
	return nail_index;
} 


function find_endpoint(B){
	let max = 0;
	for(let i = 0; i < B.length; i++){
		if (B[i] > max) max = B[i];
	}
	return max;
}

function sort_nails(C){

}

console.log(solution([1,4,5,8],[4,5,9,10],[4,6,7,10,2]));