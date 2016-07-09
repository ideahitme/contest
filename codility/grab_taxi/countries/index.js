'use strict';

console.log(
    (function solution(A) {
        let N = A.length;
        let M = A[0].length;
        let graph = Array.from({ length: N }, (_, i) => {
            return Array.from({ length: M }, (_, j) => {
            	return {
            		name: i + " " + j
            	}
            });
        });
        for(let i = 0; i < N; i++){
        	for(let j = 0; j < M; j++){
        		// if ()
        	}
        }
        return graph;
    })([
        [5, 4, 4],
        [4, 3, 4],
        [3, 2, 4],
        [2, 2, 2],
        [3, 3, 4],
        [1, 4, 4],
        [4, 1, 1]
    ])
);