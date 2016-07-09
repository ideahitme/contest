'use strict';

console.log((
    function solution(N, A) {
        let counters = Array.from(new Array(N), () => 0);
        let curMax = 0;
        let threshold = 0;
        for (let i = 0; i < A.length; i++) {
            if (A[i] === N + 1) {
                threshold = curMax
            } else {
                let counterIndex = A[i] - 1;
                counters[counterIndex] = (counters[counterIndex] < threshold) ? (threshold+1):(counters[counterIndex]+1);
                if (counters[counterIndex] > curMax) curMax = counters[counterIndex];
            }
        }
        for(let i = 0; i < counters.length; i++){
        	if (counters[i] < threshold) counters[i] = threshold;
        }
        return counters;
    }
)(5, [6, 3, 4, 4, 6, 1, 4, 4,6]));