'use strict';

//if K flags can be mounted then K-1 can be mounted too
//we can go in binary way to look it up
console.log(
	(function solution(A){
		let peaks = findPeaks(A);
		let distanceToNextPeak = findNextPeaks(peaks);
		let cur_K = Math.ceil(Math.sqrt(peaks.length));
		let result = 0;
		while(true){
			if (cur_K === 0) break;
			if (cur_K <= maxKFlagPossible(distanceToNextPeak, 0, cur_K)) { 
				result = cur_K;
				break;
			};
			cur_K--;
		}
		return result;
	})([1,5,3,4,3,4,1,2,3,4,6,2])
)

function min(a,b){
	if (a < b) return a;
	return b;
}

function max(a,b){
	if (a > b) return a;
	return b;
}

function findPeaks(A){
	let result = [0];
	for(let i = 1; i < A.length-1; i++){
		if (A[i-1] < A[i] && A[i+1] < A[i]) {
			result.push(1);
		}
		else result.push(0);
	}
	result.push(0);
	return result;
}

function maxKFlagPossible(peaks, i, K){
	if (i > peaks.length - 1) return 0;
	if (peaks[i].is_peak && !peaks[i].next_peak) return 1;
	if (!peaks[i].is_peak && !peaks[i].next_peak) return 0;

	let cur;
	if (peaks[i].is_peak){
		cur = peaks[i];
	} else cur = peaks[peaks[i].next_peak];

	let local_max = 0;
	let next_lookup = cur.next_peak;
	if (!cur.next_peak) return 1;
	if (cur.next_peak - cur.this_index >= K){
		return (maxKFlagPossible(peaks, cur.next_peak, K) + 1);
	} else {
		return  max(maxKFlagPossible(peaks, cur.next_peak, K), 1 + maxKFlagPossible(peaks, min(cur.this_index + K, peaks.length-1), K));
	}
}

function findNextPeaks(peaks){
	let result = Array.from({length:peaks.length}, () => {undefined});
	let dist = undefined;
	for(let i = peaks.length - 1; i > -1; i--){
		if (peaks[i] === 1){
			result[i] = {
				is_peak:true,
				next_peak: (i + dist),
				this_index: i
			};
			dist = 1;
		}
		else{
			result[i] = {
				is_peak:false,
				next_peak: (i + dist),
				this_index: i
			};
			if (dist != undefined) dist++;
		}
	}
	return result;
}