'use strict';

function solution(N, P, Q){
	let numbers = sieve(N).numbers;
	let primes = sieve(N).primes;
	markSemiPrimes(primes, numbers);
	let prefixSum = numSemiPrimes(numbers);
	let result = [];
	for(let i = 0; i < P.length; i++){
		let from = P[i];
		let to = Q[i];
		let num = prefixSum[to] - prefixSum[from-1];
		result.push(num);
	}
	return result;
}


function numSemiPrimes(numbers){
	let sofar = 0;
	let prefix = [];
	for(let i = 0; i < numbers.length; i++){
		if (numbers[i].semiPrime) sofar++;
		prefix.push(sofar);
	}
	return prefix;
}

function markSemiPrimes(primes, numbers){
	for(let i = 0; i < primes.length; i++){
		for(let j = i; j < primes.length; j++){
			if (primes[i]*primes[j] < numbers.length){
				numbers[primes[i]*primes[j]].semiPrime = true;
			}
		}
	}
	return numbers;
}

function sieve(N){
	let numbers = Array.from({length: N+1}, (val, index) => {
		return {
			composite: false,
			value: index
		}
	});
	let limit = Math.floor(Math.sqrt(N+1));
	let i = 2;
	while(i < limit + 1){
		if (numbers[i].composite) {
			i++; 
			continue;
		}
		let j = i;
		while(j < N + 1 - i){
			j += i;
			numbers[j].composite = true;
		}
		i++;
	}
	let primes = [];
	for(let i = 2; i < numbers.length; i++){
		if (!numbers[i].composite) primes.push(i);
	}
	return {numbers: numbers, primes: primes};
}

console.log(solution(26, [1,4,16], [26,10,20]));

