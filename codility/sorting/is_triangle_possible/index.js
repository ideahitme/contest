'use strict';

console.log(
	(function solution(A){
		if (!A || (A.length < 3)) return 0;
		A.sort(function(a,b){
			return b-a;
		});
		for(let i = 0; i < A.length-2; i++){
			if (A[i] < A[i+1] + A[i+2]) return 1;
		}
		return 0;
	})([12,3,4,2,41]));