'use strict';

(
function solution(A){
	let map = {}; //dictionary of mappings
	let result;
	for(let i = 0; i < A.length; i++){
		if (!map[A[i]+'']) map[A[i]+''] = {count: 0, index: 0};
		map[A[i]+''].count++;
		map[A[i]+''].index = i;
	}
	for(let i in map){
		if (map[i].count % 2 === 1) {
			return A[map[i].index];
		}
	}
}
)([2,1,2,4,4,7,1]);