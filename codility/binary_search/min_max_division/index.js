'use strict';

function solution(K, M, A){
	return binarySearchForSum(A, K, M);
}

function binarySearchForSum(A, K, M){
	let begin = find_max(A);
	let end = M*A.length;
	let result = -1;
	while (begin <= end){
		let middle = Math.floor((begin + end) / 2);
		let checkup = checkForSum(A, K, middle)
		if (!checkup){
			begin = middle + 1;
		}
		else{
			end = middle - 1;
			result = middle;
		}
	}
	return result;
} 

function find_max(A){
	let max = 0;
	for(let i = 0; i < A.length; i++){
		if (A[i] > max) max = A[i];
	}
	return max;
}

function checkForSum(A, K, sum){
	let blocks = 1;
	let i = 0;
	let so_far_sum = 0;
	while(i < A.length){
		so_far_sum += A[i];
		if (so_far_sum > sum){
			so_far_sum = A[i];
			blocks++;
		}
		i++;
	}
	if (blocks > K) return false;
	return true;
}


