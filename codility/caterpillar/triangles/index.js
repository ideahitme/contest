'use strict';

function solution(A){
	A = A.sort((a,b)=>a-b);
	if (A.length < 3) return 0;
	let total = 0;
	for(let small = 0; small < A.length-2; small++){
		let large = small+2;
		for(let medium = small+1; medium < A.length-1;medium++){
			while(large < A.length && A[large] < A[medium]+A[small]){
				large++;
			}
			total += large - medium - 1;
		}
	}
	return total;
}

console.log(solution([10,2,5,1,8,12]));