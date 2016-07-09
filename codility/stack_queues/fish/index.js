'use strict';

console.log(
(
    function solution(A, B) {
        let result = 0;
        let stack = [];
        for (let i = 0; i < A.length; i++) {
        	console.log(stack, result, A[i]);
        	if (B[i] === 0){
        		if (stack.length === 0) result++;
    			else {
    				while(true){
    					if (stack[stack.length - 1] > A[i]){
    						break;
    					}
    					else{
    						stack.pop();
    						if (stack.length === 0) {
    							result++;break;
    						}
    					}
    				}
    			}
        	}
        	else{
        		stack.push(A[i]);
        	}
        }
        return (result + stack.length);
    }
)([4, 3, 2, 1, 5], [0, 1, 0, 0, 0])
);
