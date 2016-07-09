'use strict';

function solution(A, X){
	if (A.length < 4) return 0;
	A = A.sort((a,b)=>a-b);
	let only_duplicates = [];
	let at_least_four = [];
	let consec = 1;
	let i = 1;
	let result = 0;
	while(i < A.length){
		if (A[i] === A[i-1]){
			consec++;
		}
		else{
			consec = 1;
		}
		if (consec === 2){
			only_duplicates.push(A[i]);
		}
		if (consec === 4){
			at_least_four.push(A[i]);
		}
		i++;
	}
	at_least_four.forEach((val)=>{
		if (val*val>=X) result++;
	});
	if (only_duplicates.length < 2) return result;
	for(let left = 0; left < only_duplicates.length; left++){
		result += find_num(left, only_duplicates.length-1, only_duplicates, X);
	}
	return result;
}

function find_num(begin, end, only_duplicates,X){
	let start = begin;
	if (begin === end) return 0;
	let index = only_duplicates.length;
	while (begin <= end){
		let middle = Math.ceil((begin + end) / 2);
		if (only_duplicates[middle]*only_duplicates[start] < X){
			if (only_duplicates[middle+1]*only_duplicates[start] >= X){
				index = middle+1;
				break;
			}
			else{
				begin = middle + 1;
			}
		}
		else{
			if (middle === start+1) {
				index = start+1;
				break;
			}
			if (only_duplicates[middle-1]*only_duplicates[start] < X){
				index = middle;
				break;
			}
			else{
				end = middle-1;
			}
		}
	}
	return only_duplicates.length-index;
}

console.log(solution([1,1,2,2,3,3,5,5,8,8,13,13,21,21], 10));
