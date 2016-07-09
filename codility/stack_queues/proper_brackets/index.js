'use strict';

console.log(
    (function solution(S) {
        S = S.split("")
        let brackets = [];
        for (let i = 0; i < S.length; i++) {
            try {
                if (S[i] === ')') {
                	if (brackets.pop() !== '(') return 0;
                }
                else if (S[i] === '}') {
                	if (brackets.pop() !== '{') return 0;
                }
                else if (S[i] === ']') {
                	if (brackets.pop() !== '[') return 0;
                }
                else brackets.push(S[i]);
            }
            catch(err){
            	return 0;
            }
        }
        return (brackets.length === 0) ? 1 : 0;
    })("((()))(()")
);
