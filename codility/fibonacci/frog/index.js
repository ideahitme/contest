'use strict';

function solution(A){
	A.push(1)
	let fibonacci = fibs(A.length);
	let reachable = Array.from({length: A.length}, () => -1);
	for(let i = 0; i < fibonacci.length; i++){
		if (fibonacci[i] < A.length && A[fibonacci[i]-1] === 1) reachable[fibonacci[i]-1] = 1;
	}
	for(let i = 0; i < A.length; i++){
		if (A[i] === 0) continue;
		if (reachable[i] > 0) continue;
		let j = 1;
		let min_value = 100*100*100;
		let found = false;
		while(fibonacci[j] <= i){
			let prev = i - fibonacci[j];
			if (reachable[prev] > 0 && min_value > reachable[prev]){
				min_value = reachable[prev];
				found = true;
			}
			j++;
		}
		if (found) reachable[i] = min_value + 1;
	}
	return reachable[reachable.length - 1];
}
/**
 * calculate fibonacci numbers up to certain point
 */
function fibs(limit){
	let res = [];
	let i = 0;
	while(true){
		if (i === 0) { res.push(1); i++ }
		else if (i === 1) { res.push(1); i++; }
		else {
			res.push(res[i-1] + res[i-2]);
			if (res[i] > limit) break;
			i++;
		}
	}
	return res;
}

console.log(solution([0,0,0,1,1,0,1,0,0,0,0]))