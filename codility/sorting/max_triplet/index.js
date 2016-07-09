'use strict';

console.log(
(function solution(A){
	A = A.sort(function(a,b){
		if (a < 0) a = -a;
		if (b < 0) b = -b;
		return b-a;
	});
	let product;
	let max_only_positive = [];
	let max_with_negative = [];
	for(let i = 0; i < A.length; i++){
		if (A[i] > 0){
			if (max_only_positive.length < 3) max_only_positive.push(A[i]);
		}
		else{
			if (max_with_negative.length < 2) max_with_negative.push(A[i]);
		}
	}
	if (A.length < 3) return undefined;
	if (A.length === 3) return A[0]*A[1]*A[2];
	if (max_only_positive.length === 0){
		return A[A.length-1]*A[A.length-2]*A[A.length-3];
	}
	if (max_only_positive.length === 1){
		return max_only_positive[0]*max_with_negative[0]*max_with_negative[1];
	}	
	if (max_only_positive.length === 2){
		return max_only_positive[0]*max_with_negative[0]*max_with_negative[1];
	}
	if (max_with_negative.length < 2){
		return max_only_positive[0]*max_only_positive[1]*max_only_positive[2];
	}
	return (max_only_positive[0]*max_only_positive[1]*max_only_positive[2]
		< max_with_negative[0]*max_with_negative[1]*max_only_positive[0]) ? 
		max_with_negative[0]*max_with_negative[1]*max_only_positive[0] : 
		max_only_positive[0]*max_only_positive[1]*max_only_positive[2];
})([-3,1,2,-2,5,6])
)