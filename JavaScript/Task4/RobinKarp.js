const fs = require("fs");
function RobinKartp(S,T)
{
    n=S.length;
    m=T.length;
    ans=[]
    x=100
    q=9999999967
    x2=Math.pow(x,m-1)%q
    SlideSum=0
    SublineSum=0
    for(i=0;i<m;i++)
    {

        SlideSum=(SlideSum+(S.charCodeAt(i)*Math.pow(x,m-i-1))%q)%q
        SublineSum=(SublineSum+(T.charCodeAt(i)*Math.pow(x,m-i-1))%q)%q
    }



    for(i=0;i<=n-m;i++)
    {
        if(SublineSum==SlideSum)
        {
            g=0
            for(; (g<m)&&(T.charAt(g)==S.charAt(i+g)) ;g++);
            if (g==m)ans.push(i);
        }
        SlideSum=((SlideSum+((q))-(S.charCodeAt(i)*x2)%q)*x+S.charCodeAt(i+m))%q
    }

    return ans;
}



const s = fs.readFileSync('input2.txt', 'utf8');
let String = s.split('\n')[0];
let SubString = s.split('\n')[1];


console.log(RobinKartp(String,SubString));