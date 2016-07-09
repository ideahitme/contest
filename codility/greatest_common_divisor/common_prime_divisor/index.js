'use strict';

function find_gcd(a, b, res){
	if (a % b === 0) return res * b;
	if (b % a === 0) return res * a;
	if (a === b) return res * a;
	if (a % 2 === 0 && b % 2 === 0) return find_gcd(a/2, b/2, res*2);
	if (a % 2 === 0) return find_gcd(a/2, b, res);
	if (b % 2 === 0) return find_gcd(a, b/2, res);
	if (a > b) return find_gcd(a-b, b, res);
	if (a < b) return find_gcd(a, b-a, res);
}

function solution(A, B){
	let result = 0;
	for(let i = 0; i < A.length; i++){
		if (areSame(A[i], B[i])) result++;
	}
	return result;
}

function areSame(a, b){
	if (a === b) return true;
	let gcd = find_gcd(a,b,1);
	let a_gcd = gcd;
	let b_gcd = gcd;
	while(a !== 1){
		a_gcd = find_gcd(a, gcd, 1);
		if (a_gcd === 1) break;
		a = a/a_gcd;
	}
	if (a !== 1) return false;
	while(b !== 1){
		b_gcd = find_gcd(b, gcd, 1);
		if (b_gcd === 1) break;
		b = b/b_gcd;
	}
	if (b !== 1) return false;
	return true;
}

console.log(solution([15, 10, 3], [75, 30, 5]));