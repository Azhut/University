const fs = require("fs");
const s = fs.readFileSync('input2.txt', 'utf8');
let T = s.split('\n')[0];
let S = s.split('\n')[1];

    N = []
    let indexes = [];


    for (let i = 0; i<S.length-1; i++){
        N[S.charAt(i)] = i + 1;
    }

    for (let i = 0; i < T.length - S.length;) {
        let j = S.length - 2, length = 0;
        for (; j >= 0 && T[i + j] === S[j]; j--) length++
        if (j < 0) indexes.push(i+1)
        let char = T.charAt(i+S.length-1);
        if (!N[char]) i += S.length
        else i += S.length-N[char];
    }
    console.log("Boyer-Moore-Horsepool: ", indexes)

////////////BMHorspool



    n = T.length;
    m = S.length;
    arr = new Array();
    suffshift = new Array()
    z = new Array()
    maxZidx = 0
    maxZ = 0;
    for (var j = 0; j <=m; j++) {
        z[j]=0;
        suffshift[j]=m;
    }


    for (var j = 1; j < m; j++) {
        if (j <= maxZ)
            z[j] = Math.min(maxZ - j + 1, z[j - maxZidx]);
        while ( (j + z[j] < m) && (S.charAt(m - 1 - z[j]) == S.charAt(m - 1 - (j + z[j]))) )
            z[j]+=1;
        if (j + z[j] - 1 > maxZ) {
            maxZidx = j;
            maxZ = j + z[j] - 1;
        }
    }
    for (var j = m - 1; j > 0; j--){
        suffshift[m - z[j]] = j;
    }
    r = 0;
    for (var j = 1;  j <= m - 1; j++){
        if ((j + z[j]) == m){
            for(r; r <= j; r++){
                if (suffshift[r] == m)
                    suffshift[r] = j;
            }
        }
    }
    i=0
    bound = 0;
    F = new Array()
    for(j=0;j<S.length-1;j++)
        F[S.charAt(j)]=j+1


    while (i<=n-m){
        j=m-1;
        while (j>= bound && ( T.charAt(i+j) == S.charAt(j) ) )
            j--;

        if (j< bound){
            arr.push(i+1);
            bound = m - suffshift[0];
            j = -1;
            i += suffshift[0];
        }

        else
        {
            bound = 0;
            if ( S.indexOf(T.charAt(i + j)) > -1 ){
                StopTable = F[T.charAt(i + j)];
            }
            else{
                StopTable = 0;
            }
            i = Math.max(i + suffshift[j+1], i + j + 1 - StopTable);
        }
    }
console.log("Boyer-Moore: ", indexes)
