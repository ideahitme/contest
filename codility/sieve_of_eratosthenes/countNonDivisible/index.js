'use strict';

function soluton(A){
	let sieveOfA = sieve(A);
	let result = [];
	for(let i = 0; i < A.length; i++){
		result.push(A.length - sieveOfA[A[i]]);
	}
	return result;
}

function sieve(A){
	let max = find_max(A);
	let countArray = Array.from({length: max+1}, () => 0);
	for(let i = 0; i < A.length; i++){
		let j = A[i];
		while(j <= max){
			countArray[j]++;
			j += A[i];
		}
	}
	return countArray;
}

function find_max(A){
	let max = 0;
	for(let i = 0; i < A.length; i++){
		if (A[i] > max) max = A[i];
	}
	return max;
}

console.log(soluton([3,1,2,3,6]));