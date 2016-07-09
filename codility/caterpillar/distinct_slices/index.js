'use strict';

function solution(M, A){
	let count = countArray(M);
	let left = 0;
	let right = 0;
	let total = 0;
	while(true){
		if (count[A[right]] === 1){
			count[A[left]]--;
			total+=right-left;
			left++;
		}
		else{
			count[A[right]]++
			right++;
		}
		if (right === A.length){
			total += (right-left)*(right-left+1)/2;
			break;
		}
	}
	return total;
}

function countArray(M){
	return Array.from({length: M+1}, () => 0);
}


console.log(solution(6, [3,4,5,5,2]));