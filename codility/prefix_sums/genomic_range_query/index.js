'use strict';

function howManyInInterval(S, val){
	let res = [];
	let sofar = 0;
	for(let i = 0; i < S.length; i++){
		if (S[i] === val) sofar++;
		res.push(sofar);
	}
	return res;
}

function min(a,b){
	if (a < b) return a;
	return b;
}

console.log
((
    function solution(S, P, Q) {
    	let mapping = {
    		A: howManyInInterval(S, 'A'),
    		C: howManyInInterval(S, 'C'),
    		G: howManyInInterval(S, 'G'),
    		T: howManyInInterval(S, 'T')
    	}
    	let result = [];
    	let letters = ['A', 'C', 'G', 'T'];
    	for(let j = 0; j < P.length; j++){
    		for(let i = 0; i < 4; i++){
    			let toCheck = mapping[letters[i]];
    			let from = P[j];
    			let to = Q[j];
    			if (from === to) {
    				result.push(letters.indexOf(S[from]) + 1);
    				break;
    			}
    			if (from === 0 && toCheck[to] > 0){
    				result.push(i+1);
    				break;
    			}
    			if (toCheck[to]-toCheck[from-1]>0){
    				result.push(i+1);
    				break;
    			}
    		}
    	}
    	return result;
    }
)("CAGCCTA",[2,5,0,2],[4,5,6,2]));
