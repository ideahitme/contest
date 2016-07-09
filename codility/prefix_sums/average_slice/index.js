'use strict';


//the key idea here is that the slice size has to be either two or three
//because if it is more than 3 we can achieve contradiction by checking that 
//(a_1+..+a_(n-2)+a_(n-1)+a_n)/n<((a_1+..+a_(n-2))/(n-2))
//(a_1+..+a_(n-2)+a_(n-1)+a_n)/n<(a_(n-1)+a_n)/2
//cannot hold at the same time
function prefixSums(A){
	let sums = [A[0]];
	let sofar = A[0];
	for(let i = 1; i < A.length; i++){
		sofar += A[i];
		sums.push(sofar);
	}
	return sums;
}

function minPrefixSumSize(sums, size){ //size is 2,3,4..,sums.length-1
	let min = {
		value: sums[size-1],
		from_index: 0,
		size: size
	};
	for(let i = 1; i < sums.length-size+1; i++){
		if (sums[size-1+i]-sums[i-1] < min.value){
			min.value = sums[size-1+i]-sums[i-1];
			min.from_index = i;
		}
	}
	return min;
}



console.log(
(function solution(A){
	let sums = prefixSums(A);
	let result = 1000000;
	let sizeTwo = minPrefixSumSize(sums, 2);
	let sizeThree = minPrefixSumSize(sums, 3);
	if (sizeTwo.value/2 < sizeThree.value/3){
		result = sizeTwo.from_index;
	}
	else if (sizeTwo.value/2 > sizeThree.value/3){
		result = sizeThree.from_index;
	}
	else if (sizeTwo.value/2 === sizeThree.value/3){
		result = (sizeTwo.from_index < sizeThree.from_index) ? sizeTwo.from_index : sizeThree.from_index;
	}
	return result;
})([4,2,2,5,1,5,8])
);
