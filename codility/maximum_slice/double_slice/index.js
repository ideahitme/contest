'use strict';

console.log
(
	(function solution(A){
		if (A.length <= 3) return 0;
		A.pop();
		A.shift();
		let endsAt = bestSumsEndAt(A);
		let startsAt = bestSumsStartAt(A);
		let max = 0;
		for(let i = 0; i < A.length; i++){
			if (i === 0){
				if (max < startsAt[1]){
					max = startsAt[1];
				}
			}
			if (i === (A.length-1)){
				if (max < endsAt[A.length-2]){
					max = endsAt[A.length-2];
				}
			}	
			if (endsAt[i-1] + startsAt[i+1] > max) {
				max = endsAt[i-1] + startsAt[i+1];
			}
		}
		if (A.length === 2){
			if (A[0] < 0 && A[1] < 0) return 0;
			if (A[0] > A[1]) return A[0];
			if (A[1] > A[0]) return A[1];
		}
		if (max < 0) return 0;
		return max;
	})([5, 0, 1, 0, 5])
)

function max(a,b){
	if (a > b) return a;
	return b;
}

function bestSumsEndAt(A){
	let result = [];
	let max_ending = 0;
	let max_slice = 0;
	for(let i = 0; i < A.length; i++){
		max_ending = max(0, max_ending + A[i]);
		result.push(max_ending);
	}
	return result;
}
function bestSumsStartAt(A){
	let result = [];
	let max_starting = 0;
	let max_slice = 0;
	for(let i = A.length-1; i > -1; i--){
		max_starting = max(0, max_starting + A[i]);
		result.unshift(max_starting);
	}
	return result;
}