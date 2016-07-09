'use strict';

console.log(
(function solution(A){
	let counter = Array.from({length:A.length}, () => 0);
	//values equal number of 1's to the right
	let found = 0;
	for(let i = A.length-1; i > -1; i--){
		if (A[i] === 1){
			found++;
		}
		counter[i] = found;
	}
	console.log(counter);
	let result = 0;
	for(let i = 0; i < A.length; i++){
		if (A[i] === 0) result += counter[i];
		if (result > 1000000000) return -1;
	}
	return result;
})([0,1,0,1,1])
);