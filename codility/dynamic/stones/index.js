'use strict';

function solution(A){
	if (A.length < 1) return 0;
	if (A.length === 1){
		return A[0];
	}
	if (A.length === 2){
		return A[0] + A[1];
	}
	if (A.length === 3){
		if (A[1] > 0){ 
			return A[0] + A[1] + A[2];
		}
		else return A[0]+A[2];
	}

	let dp = Array.from({length: A.length});
	dp[0] = A[0];
	dp[1] = A[0] + A[1];
	dp[2] = (A[1] > 0) ? A[0] + A[1] + A[2] : A[0] + A[2]; 
	let i = 3;
	while(i < A.length){
		let from = max_in_array([0, i - 6]);
		dp[i] = max_in_array(dp.slice(from,i))+A[i];
		i++;
	}
	return dp[dp.length-1];
}

function max(a,b){
	if (a > b) return a;
	return b;
}

function max_in_array(els){
	let max = els[0];
	for(let i = 0; i < els.length; i++){
		if (els[i] > max)  max = els[i];
	}
	return max;
}


console.log(solution([1,-2,0,4]));