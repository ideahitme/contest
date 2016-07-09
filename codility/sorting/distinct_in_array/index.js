'use strict';

console.log(
(function solution(A){
	A = A.sort();
	let last = A[0];
	let different = 1;
	for(let i = 1; i < A.length; i++){
		if (A[i] != A[i-1]) different++;
	}
	return different;
})([2,1,1,2,3,1,1,1,3,4]));