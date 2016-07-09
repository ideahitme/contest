'use strict';
(function solution(N){
	try {
		N = parseInt(N);
	} catch(err){ return 0; }

	var binaryString = N.toString(2);
	console.log(binaryString);
	var foundLastOne = false;
	var cur = 0;
	var last_max = 0;
	for(let i = binaryString.length - 1; i > -1; i--){
		if (binaryString[i] === '1' && !foundLastOne) {
			foundLastOne = true;
			continue;
		}
		if (foundLastOne){
			if (binaryString[i] === '1') {
				cur = 0;
			} else {
				cur++;
			}
			if (cur > last_max) last_max = cur;
		}
	}	
	console.log(last_max);
	return last_max;
})(process.env.N)