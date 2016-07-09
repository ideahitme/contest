'use strict';

function solution(N, M){
	let gcd = find_gcd(N, M, 1);
	let lcm = (N*M)/gcd;
	let i =  lcm/M;
	return i;
}

function find_gcd(a, b, res){
	if (a === b) return res * a;
	if (a % 2 === 0 && b % 2 === 0) return find_gcd(a/2, b/2, res*2);
	if (a % 2 === 0) return find_gcd(a/2, b, res);
	if (b % 2 === 0) return find_gcd(a, b/2, res);
	if (a > b) return find_gcd(a-b, b, res);
	if (a < b) return find_gcd(a, b-a, res);
}

console.log(solution(12, 6));

// M%N -> 2*M%N-> 3*M%N -> 4*M%N -> ... i*M%N
// 

//min i, s.t. (i-1)*M%N = 0
//
//
//0, 6, 2, 8, 4, 0