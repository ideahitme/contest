'use strict';

console.log
(
	(function solution(N){
		let side_a = Math.floor(Math.sqrt(N));
		while(side_a !== 1){
			if (N % side_a === 0) break;
			side_a--;
		}
		let side_b = N/side_a;
		return (side_a + side_b ) *2;
	})(4)
)