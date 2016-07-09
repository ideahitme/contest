'use strict';

console.log(
(function solution(H){
	let stack = [];
	let result = 0;
	for(let i = 0; i < H.length; i++){
		let height = H[i];
		while(stack.length != 0 && stack[stack.length-1] > height){
			stack.pop();
		}
		if (stack.length != 0 && stack[stack.length-1] === height){
			continue;
		}
		else{
			result++;
			stack.push(height);
		}
	}
	return result;
})([8,8,5,7,9,8,7,4,8])
)