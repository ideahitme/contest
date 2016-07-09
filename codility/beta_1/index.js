'use strict';

//palindrome 
function solution(S){
	let struct = removeConsecSameChars(S.split(''));
	let s_array = struct.processed;
	let result = struct.to_add;

	return result;
}

function removeConsecSameChars(word){
	let processed = [word[0]];
	let consec = 1;
	let to_add = 0;
	for(let i=1; i < word.length; i++){
		if (word[i] === word[i-1]){
			consec++;
		}
		else{
			to_add += (consec-1)*(consec)/2;
			consec = 1;
			processed.push(word[i]);
		}
	}
	if (consec > 1){
		to_add += (consec-1)*(consec)/2;
	}
	return {
		to_add: to_add,
		processed: processed
	};
}
console.log(solution('aaaa'));