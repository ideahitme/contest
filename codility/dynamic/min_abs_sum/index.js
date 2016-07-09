'use strict';

function solution(A){
	A = turnToPositive(A);
	let max = find_max(A);
	let count_array = countArray(A, max);
	let sum = totalSum(A);
	let dp = Array.from({length: sum+1}, () => -1);
	dp[0] = 0;
	for(let i = 0; i < max+1; i++){
		if (count_array[i] > 0){
			let a = i;
			for(let j = 0; j < sum+1;j++){
				if (dp[j] >= 0){
					dp[j] = count_array[i];
				}
				else if (dp[j-a] > 0 && j >= a){
					dp[j] = dp[j-a] - 1;
				}
			}
		}
	}
	let res = sum;
	let half = (sum - sum%2)/2;
	for(let i = 0; i < half+1; i++){
		if (dp[i] >= 0){
			res = min(res, sum-2*i);
		}
	}
	return res;
}

function min(a,b){
	if (a < b) return a;
	else return b;
}

function totalSum(A){
	let sum = 0;
	for(let i = 0; i < A.length; i++){
		sum += A[i];
	}
	return sum;
}

function turnToPositive(A){
	for(let i = 0; i < A.length; i++){
		if (A[i] < 0) A[i] = -A[i];
	}
	return A;
}

function countArray(A, max){
	let count_array = Array.from({length:max+1}, () => 0);
	for(let i = 0; i < A.length; i++){
		count_array[A[i]]++;
	}
	return count_array;
}

function find_max(A){
	let max = -1;
	for(let i = 0; i < A.length; i++){
		if (A[i] > max) max = A[i];
	}
	return max;
}

console.log(solution([1,5,2,-2]));