'use strict';

function isPrime(n){
	return n == 2 || n == 3 || n == 5 || n == 7;
}


function num_composites(numbers){
	var dim = numbers.length;
	var composites_for_row = []
	for(var i = 0; i < dim; i++){
		var add = []
		for(var j = 0; j < dim; j++){
			add.push(0)
		}
		composites_for_row.push(add);
	}
	for(var top = 0; top < dim; top++){
		for(var left = 0; left < dim; left++){
			if (left == 0){
				if (!isPrime(numbers[top][left])) {
					composites_for_row[top][0] = 1
				}
			}
			else {
				if (!isPrime(numbers[top][left])) {
					composites_for_row[top][left] = composites_for_row[top][left-1] + 1
				}
				else{
					composites_for_row[top][left] = composites_for_row[top][left-1]
				}
			}
		}
	}
	var composites_between_rows = []
	for(var i = 0; i < dim; i++){
		var add = []
		for(var j = 0; j < dim; j++){
			var more_add = []
			for(var k = 0; k < dim; k++){
				more_add.push(0);
			}
			add.push(more_add)
		}
		composites_between_rows.push(add);
	}	
	for(var top = 0; top < dim; top++){
		for(var bottom = top; bottom < dim; bottom++){
			for(var left = 0; left < dim; left++){
				if (bottom == top){
					composites_between_rows[top][bottom][left] = composites_for_row[top][left]
				}
				else{
					composites_between_rows[top][bottom][left] = composites_between_rows[top][bottom-1][left] + composites_for_row[bottom][left]
				}
			}
		}
	}
	return composites_between_rows
}

function grundy_numbers(numbers, comps){
	var dim = numbers.length;
	var grundy_numbers = []
	for(var i = 0; i < dim; i++){
		var add = []
		for(var j = 0; j < dim; j++){
			add.push(0)
		}
		grundy_numbers.push(add);
	}
	for(var height = 0; height < dim; height++){
		for(var width = 0; width < dim; width++){
			var local_grundy = []
			for(var i = 0; i < dim-height; i++){
				var add = []
				for(var j = 0; j < dim-width; j++){
					add.push(0)
				}
				local_grundy.push(add);
			}
			for(var top = 0; top < dim - height; top++){
				for(var left=0; left < dim - width; left++){
					if (height == 0 && width == 0){
						local_grundy[top][left] = 0
					}
					else{
						var allPrime = true
						if (left == 0){
							if (comps[top][top+height][left+width] > 0){
								allPrime = false
							}
						}
						else{
							if (comps[top][top+height][left+width]-comps[top][top+height][left-1] > 0){
								allPrime = false
							}
						}
						if (allPrime){
							local_grundy[top][left] = 0
						}
						else{
							var answers = []
							for(var j = 0; j < 2*dim; j++){
								answers.push(0)
							}
							for(var j = 0; j < width; j++){
								var val = grundy_numbers[height][j][top][left]^grundy_numbers[height][width-j-1][top][left+j+1]
								if (val < 2*dim){
									answers[val] += 1
								}
							}
							for(var i = 0; i < height; i++){
								var val = grundy_numbers[i][width][top][left]^grundy_numbers[height-i-1][width][top+i+1][left]
								if (val < 2*dim) answers[val] += 1
							}
							var _i = 0
							for(var i = 0; i < answers.length; i++){
								if (answers[i] == 0){
									_i = i;
									break;
								}
							}
							local_grundy[top][left] = i
						}
					}
				}
			}
			grundy_numbers[height][width] = local_grundy
		}
	}
	return grundy_numbers[dim-1][dim-1][0][0]
}

function solution(numbers){
	var dim = numbers.length;
	if (dim < 2){
		return 'Second';
	}
	var comps = num_composites(numbers);
	if (comps[0][dim-1][dim-1] == 0){
		return 'Second'
	}
	var answer = grundy_numbers(numbers, comps)
	if(answer > 0){
		return 'First'
	}
	else{
		return 'Second'	
	}
}

function processData(input) {
	input = input.split('\n');
	var num_cases = parseInt(input[0]);
	var currentLine = 1;
	for(var i = 0; i < num_cases; i++){
		var length = parseInt(input[currentLine]);
		var numbers = []
		for(var j = 0; j < length; j++){
			currentLine++;
			var row = []
			var info = input[currentLine].split(" ");
			for(var k = 0; k < length; k++){
				row.push(parseInt(info[k]))
			}
			numbers.push(row);
		}
		var answer = solution(numbers);
		console.log(answer);
		currentLine++;
	}
} 


process.stdin.resume();
process.stdin.setEncoding("ascii");
var _input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});