'use strict';

function timeToMinutes(T) {
	return parseInt(T.substring(0,2)) * 60 + parseInt(T.substring(3,5));
}

console.log(
    (
        function solution(E, L) {
        	let from = timeToMinutes(E);
        	let to = timeToMinutes(L);
        	let totalMinutes = to - from;
        	let totalCost = 2; //for entrance
        	if (totalMinutes < 61) return 5;
        	else return (5 + Math.ceil((totalMinutes-60)/60)*4);
        })('12:00', '12:01')
);