const fs = require("fs");
function HashMaping(S,T)
{
    n=S.length;
    m=T.length;
    ans=[]
    SlideSum=0; SublineSum=0;
    for(i=0;i<m;i++)
    {
        SlideSum+=S.charCodeAt(i)
        SublineSum+=T.charCodeAt(i)
    }

    for(i=0;i<=n-m;i++)
    {
        if(SublineSum==SlideSum)
        {
            g=0
            for(; (g<m)&&(T.charAt(g)==S.charAt(i+g)) ;g++);
            if (g==m)ans.push(i);
        }
        SlideSum+=S.charCodeAt(i+m)-S.charCodeAt(i)
    }
    return ans;
}




const s = fs.readFileSync('input2.txt', 'utf8');
let String = s.split('\n')[0];
let SubString = s.split('\n')[1];


console.log(HashMaping(String,SubString));