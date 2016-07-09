function solution(A){
    var len = A.length;
    var result = 0;
    var count = [];
    for(var i = 0; i < len+1; i++){
        count.push([-1,-1]);
    }
    for(var i = 0; i < len; i++){
        var val = A[i];
        if (count[A[i]][0] == -1){
            count[A[i]][0] = i;
        }
        else{
            count[A[i]][1] = i;
        }
    }
    for(var i = 0; i < len+1; i++){
        if (count[i][1] > -1) result = Math.max(result, count[i][1]-count[i][0]);
    }
    return result;
}

// def solution(A):
//     N = len(A)
//     result = 0
//     count = [[-1 for j in xrange(2)] for i in xrange(N+1)]
//     for i in xrange(N):
//         val = A[i]
//         if count[val][0] == -1:
//             count[val][0] = i
//         else:
//             count[val][1] = i
//     for i in xrange(N):
//         if count[val][0] != -1 and count[val][1] != -1:
//             result = max(result, count[val][1]-count[val][0])
//     return result

