'use strict';

console.log(
	(function solution(A){
		let leader = findLeaderValue(A);
		if (!leader) return 0;
		else {
			let equileaders = 0;
			let total = leader.counter;
			let sofar = 0;
			for(let i = 0; i < A.length; i++){
				if (A[i] === leader.value) sofar++;
				if (sofar*2 > (i+1) && ((total-sofar)*2>(A.length-i-1))){
					equileaders++;
				}
			}
			return equileaders;
		}
	})([4,3,4,4,4,2])
);

function findLeaderValue(A){
	let stack = [];
	for(let i = 0; i < A.length; i++){
		if (stack.length === 0) stack.push(A[i]);
		else {
			if (A[i] != stack[stack.length-1]){
				stack.pop();
			}
			else {
				stack.push(A[i]);
			}
		}
	}
	if (stack.length === 0) return undefined;
	let contender = stack[0];
	let appearance = 0;
	for(let i = 0; i < A.length; i++){
		if (contender === A[i]) appearance++;
	}
	if (2*appearance > A.length) return {
		value: contender,
		counter: appearance
	}
	return undefined;
}