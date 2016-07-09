'use strict';

function solution(K, A){
	let total = 0;
	let cur = 0;
	let i = 0;
	while(i < A.length){
		cur+=A[i];
		if (cur >= K){
			total++;
			cur = 0;
		}
		i++;
	}
	return total;
}

console.log(solution(4, [1,2,3,4,1,1,3]))
