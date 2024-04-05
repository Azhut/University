const fs = require("fs");

function BruteForce(S,T)
{
    ans=[]
    n=S.length;
    m=T.length;
    for(i=1; i<=n-m ; i++){
        g=0;
        while((T.charAt(g)==S.charAt(g+i))&&(g<m)){g++;}
        if (g==m){
            ans.push(i);
        }
    }
    return ans
}



const s = fs.readFileSync('input2.txt', 'utf8');
let String = s.split('\n')[0];
let SubString = s.split('\n')[1];


console.log(BruteForce(String,SubString));

