'use strict';

function solution(A){
	let break_point = findBreakPoint(A);
	if (break_point === 0 || break_point === A.length){
		return countDistinct(A, 0, A.length - 1);
	}
	let total = countDistinct(A, 0, break_point - 1) + 
		countDistinct(A, break_point, A.length - 1);
	let left = break_point - 1;
	let right = break_point + 1;
	while(true){
		if (A[left] + A[right] === 0){
			total--;
			while(true){
				if (left === 0) return total;
				if (A[left] === A[left-1]){
					left--;
				}
				else break;
			}
			left--;
			while(true){
				if (right === A.length - 1) return total;
				if (A[right] === A[right+1]){
					right++;
				}
				else break;
			}
			right++;
		}
		if (A[left] + A[right] > 0) {
			left = left - 1;
			if (left === -1) return total;
		}
		if (A[left] + A[right] < 0) {
			right = right + 1;
			if (right === A.length) return total;
 		}
	}
	return total;
}

function findBreakPoint(A){
	let break_point = 0;
	let i = 0;
	while(true){
		if (A[break_point] >= 0){
			return break_point;	
		}
		else {
			break_point++;
		}
		if (break_point >= A.length) break;
	}
	return break_point;
}

function countDistinct(A, from, to){
	let total = to - from + 1;
	for(let i = from; i < to; i++){
		if (A[i] === A[i+1]) total--;
	}
	return total;
}

console.log(solution([-5,-3,-1, 0, 2, 3, 5, 7]));