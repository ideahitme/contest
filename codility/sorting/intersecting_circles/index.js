'use strict';

console.log
(
	(function solution(A){
		A = convert(A);
		A = A.sort((a, b) => {
			if (a.value != b.value){
				return a.value - b.value;
			}
			else{
				if (a.is_left)
					return -1;
				else return 1;
			}
		});
		let result = 0;
		let active_circles = 0;
		for(let i = 0; i < A.length; i++){
			if (A[i].is_left){
				result += active_circles;
				active_circles++;
			}
			else{
				active_circles--;
			}
		}
		return (result > 10*1000*1000) ? -1 : result;
	})([0,1,0])
);

function intersect(a_i, a_j, i, j){
	if (i === j) return true;
	if (i < j){
		return ((j-i) <= (a_i+a_j));
	}
	else{
		return ((i-j) <= (a_i+a_j));
	}
}

function convert(A){
	let B = [];
	A.forEach((val, i) => {
		B.push({
			value: i - val,
			is_left: true
		});
		B.push({
			value: i + val,
			is_left: false
		});
	})
	return B;
}