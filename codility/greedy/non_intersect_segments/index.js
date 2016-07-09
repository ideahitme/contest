'use strict';

function solution(A, B){
	if (A.length === 1) return 1;
	let prev_end = B[0];
	let total = 1;
	let i = 1;
	while(i < A.length){
		if (A[i] > prev_end){
			total++;
			prev_end = B[i];
		}
		i++;
	}
	return total;
}

console.log(solution([1,3,7,9,9],[5,6,8,9,10]));