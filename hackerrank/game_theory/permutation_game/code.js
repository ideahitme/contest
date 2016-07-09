function grundy_number(selections, selection, perm, grundies) {
	if (grundies[selection] > 0){
		return grundies[selection];
	}
    var previous = null;
    var isIncreasing = selections[selection];
    if (isIncreasing) {
        return 0;
    } else {
        var answer = []
        for (var i = 0; i < 20; i++) {
            answer[i] = 0;
        }
        for (var i = 0; i < perm.length; i++) {
        	if ((selection >> i) & 1 == 1) {
        		var new_selection = selection ^ Math.pow(2, i);
        		// console.log(selection, i, new_selection)
        		var new_val = grundy_number(selections, new_selection, perm, grundies);
        		answer[new_val] += 1
        	}
        }
        var grundy = 0;
        for (var i = 0; i < 20; i++) {
            if (answer[i] == 0) {
                grundy = i;
                break;
            }
        }
        grundies[selection] = grundy;
        return grundy;
    }
}

function solution(perm, size) {
    var selections = new Array(Math.pow(2, size));
    var grundies =  Array.apply(null, Array(Math.pow(2, size))).map(function(){return -1});
    for (var j = 1; j < selections.length; j++) {
        var previous = null;
        var isIncreasing = true;
        for (var i = 0; i < size; i++) {
            if ((j >> i) & 1 == 1) {
                if (!previous) {
                    previous = perm[size-i-1]
                } else {
                    if (previous < perm[size-i-1]) {
                        isIncreasing = false;
                        break;
                    } else {
                        previous = perm[size-i-1];
                    }
                }
            }
        }
        selections[j] = isIncreasing;
    }
    if (grundy_number(selections, selections.length-1, perm, grundies) > 0){
    	return 'Alice'
    }
    else{
    	return 'Bob'
    }
}


function processData(input) {
    input = input.split('\n');
    var num_cases = parseInt(input[0]);
    var currentLine = 1;
    for (var i = 0; i < num_cases; i++) {
        var length = parseInt(input[currentLine]);
        currentLine++;
        var line = input[currentLine].split(" ")
        var numbers = []
        for (var j = 0; j < length; j++) {
            numbers[j] = parseInt(line[j])
        }
        var answer = solution(numbers, length);
        console.log(answer);
        currentLine++;
    }
}


process.stdin.resume();
process.stdin.setEncoding("ascii");
var _input = "";
process.stdin.on("data", function(input) {
    _input += input;
});

process.stdin.on("end", function() {
    processData(_input);
});
