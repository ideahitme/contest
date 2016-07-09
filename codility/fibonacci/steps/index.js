'use strict';

function solution(A, B){
	let max = find_max(A);
	let fibs = calc_fibs(max);
	let res = [];
	for(let i = 0; i < A.length; i++){
		let val = fibs[A[i]] % Math.pow(2, B[i]);
		res.push(val);
	}
	return res;
}

function find_max(A){
	let max = -1;
	for(let i = 0; i < A.length; i++){
		if (A[i] > max) max = A[i];
	}
	return max;
}

function calc_fibs(until){
	let a = 1;
	let b = 1;
	let fibs = [a,b];
	for(let i = 2; i < until + 1; i++){
		fibs[i] = (fibs[i-1] + fibs[i-2]) % Math.pow(2, 30);
	}
	return fibs;
}

console.log(solution([4,4,5,5,1],[3,2,4,3,1]));