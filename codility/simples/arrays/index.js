'use strict';
(
function solution(A, K) {
	let sizeOfA = A.length;
	if (sizeOfA <= 1 || K === 0) return A;
	K = K%sizeOfA; //don't make redundant operations;
	//now index 0 will definitely go to position K 
	//1 -> (K+1)%sizeOfA so on...
	let B = A.slice(0);
	for(let i = 0; i < sizeOfA; i++){
		A[i] = B[(sizeOfA-K+i)%sizeOfA];
	}
	console.log(A);
	return A;
}
)([1,2,3,4,5], 3);