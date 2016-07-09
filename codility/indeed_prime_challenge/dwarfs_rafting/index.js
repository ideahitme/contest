'use strict';

function solution(N, S, T){
	let seats = Array.from({length: N}, () => Array.from({length: N}, () => {return {occupied: undefined}}));
	let barrels = parseSeats(S);
	let old_dwarfs = parseSeats(T);
	for(let i = 0; i < barrels.length; i++){
		seats[barrels[i].row][barrels[i].column].occupied = 'barrel';
	}
	for(let i = 0; i < old_dwarfs.length; i++){
		seats[old_dwarfs[i].row][old_dwarfs[i].column].occupied = 'dwarf';
	}
	return find_empty_seats_quarters(seats) - old_dwarfs.length;
	//indicate taken seats
}

function parseSeats(string){
	let parsed = [];
	if (string.length === 0) return [];
	parsed = string.split(' ').map((val) => {
		let digit = parseInt(val.substring(0, val.length-1));
		let char = val[val.length-1];
		return {
			row: digit - 1,
			column: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'.indexOf(char)
		};
	});
	return parsed; 
}

function find_empty_seats_quarters(seats){
	let quarter1 = 0;
	let quarter2 = 0;
	let quarter3 = 0;
	let quarter4 = 0;
	for(let i = 0; i < seats.length; i++){
		for(let j = 0; j < seats.length; j++){
			if (seats[i][j].occupied === "barrel") continue;
			if (i >= 0 && i < seats.length/2){
				if (j >= 0 && j < seats.length/2){
					quarter1++;
				}
				else{
					quarter2++;
				}
			}
			else{
				if (j >= 0 && j < seats.length/2){
					quarter3++;
				}
				else{
					quarter4++;
				}
			}
		}
	}
	return 2*min(quarter1, quarter4) + 2*min(quarter2, quarter3);	
}


function min(a,b){
	if (a < b) return a;
	return b;
}

console.log(solution(4, '1B 1C 4B 1D 2A', '3B 2D'));