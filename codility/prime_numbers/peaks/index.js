'use strict';

console.log
(
	(function solution(A){
		let divisors = all_divisors(A);
		let peaks = peaksSoFar(A);
		console.log(peaks);
		console.log(divisors);
		if (!peaks || peaks[peaks.length-1] === 0) return 0;
		let max_blocks = 1;
		while(true){
			if (divisors.length === 0) break;
			let divisor = divisors.pop();
			if (divisor === 2 || divisor === 1 || divisor === A.length) continue;
			let each_has = true;
			for(let i = 0; i < (A.length - divisor); i = i + divisor){
				if (peaks[i+divisor] - peaks[i] === 0){
					each_has = false;
					break;
				}
			}
			if (each_has){
				max_blocks = (A.length/divisor > max_blocks) ? (A.length)/divisor : max_blocks;
			}
		}
		return max_blocks;
	})([1,2,3,4,3,4,1,2,3,4,6,2])
);

function peaksSoFar(A){
	let sofar = 0;
	let result = [0];
	if (A.length < 3) return undefined;
	for(let i = 1; i < A.length; i++){
		if (A[i-1] < A[i] && A[i+1] < A[i]) {
			i++;
			sofar++;
			result.push(sofar);
			result.push(sofar);
		}
		else result.push(sofar);
	}
	return result;
}

function all_divisors(A){
	//just need those that are more than three
	let small = [];
	let large = [];
	let result = [];
	for(let i = 1; i <= Math.floor(Math.sqrt(A.length)); i++){
		if (A.length % i === 0){
			small.push(i);
			large.unshift(A.length/i);
		}
	}
	return small.concat(large);
}