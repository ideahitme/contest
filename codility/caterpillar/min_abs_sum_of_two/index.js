'use strict';

function solution(A) {
	if (A.length === 1) return Math.abs(2*A[0]);
    A = A.sort((a, b) => a - b);
    let breakpoint = find_breakpoint(A);
    if (breakpoint === 0) {
        return 2*A[0];
    }
    if (breakpoint === A.length) {
        return Math.abs(2*A[A.length - 1]);
    }
    let minimum = Math.abs(A[breakpoint-1] + A[breakpoint]);
    for (let left = 0; left < breakpoint; left++) {
        let begin = breakpoint;
        let end = A.length - 1;
        if (A[left]+A[breakpoint]>0){
        	minimum = min(minimum, Math.abs(A[left]+A[breakpoint]));
        	continue;
        }
        if (A[left]+A[A.length-1]<0){
        	minimum = min(minimum, Math.abs(A[left]+A[A.length-1]));
        	continue;
        }
        while (begin <= end) {
            let middle = Math.floor((begin + end) / 2);
            if (A[left]+A[middle] <= 0 && A[left] + A[middle+1] >= 0) {
            	minimum = min(minimum, Math.abs(A[left]+A[middle]));
            	minimum = min(minimum, Math.abs(A[left]+A[middle+1]));
            }
            if (A[left]+A[middle] < 0) {
                begin = middle + 1;
            } else end = middle - 1;
        }
    }
    return minimum;
}

function min(a,b){
	if (a < b) return a;
	return b;
}

function find_breakpoint(A) {
    let break_point = 0;
    let i = 0;
    while (true) {
        if (A[break_point] >= 0) {
            return break_point;
        } else {
            break_point++;
        }
        if (break_point >= A.length) break;
    }
    return break_point;
}

console.log(solution([-8, 4, 5, -10, 3]));
