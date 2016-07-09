'use strict';

function solution(A){
	let prefix_array = prefixArray(A);
	let max = -1;
	for(let i = 0; i < prefix_array.length; i++){
		if (prefix_array[i] > max) max=prefix_array[i];
	}
	return max;
}

function prefixArray(A){
	let count_array = Array.from({length:A.length},() => -1);
	for(let i = 0; i < A.length; i++){
		if (count_array[A[i]] === -1) count_array[A[i]] = i;
	}
	return count_array;
}

console.log(solution([2,2,1,0,1]));