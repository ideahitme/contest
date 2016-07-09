'use strict';

const binarySearch = module.export = function(A, x){
	let len = A.length;
	let begin = 0;
	let end = len - 1;
	let result = -1;
	while (begin <= end){
		let middle = Math.floor((begin + end) / 2);
		if (A[middle] <= x){
			begin = middle + 1;
			result = middle;
		}
		else end = middle - 1;
	}
	return result;
} 

console.log(binarySearch([1,4,5,9,10,23,52], 23))