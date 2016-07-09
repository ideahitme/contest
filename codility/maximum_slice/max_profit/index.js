'use strict';

console.log
(
	(function solution(A){
		if (A.length === 0) return 0;
		let minArray = minSoFarArray(A);
		let max = 0;
		for(let i = 0; i < A.length; i++){
			if (A[i]-minArray[i] > max) max = A[i]-minArray[i];
		}
		return (max > 0) ? max: 0;
	})([23171,21011,21123,21366,21013,21367])
)

function minSoFarArray(A){
	let min = A[0];
	let minArray = [A[0]];
	for(let i = 1; i < A.length; i++){
		if (min > A[i]) min = A[i];
		minArray.push(min);
	}
	return minArray;
}
