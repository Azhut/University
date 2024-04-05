let fs=require("fs");
let File=fs.readFileSync("input2.txt","utf8");
line=File.split("\n");
console.log(line);
let T=line[0].split("\r")[0];
let S=line[1];
let m=S.length;
let n=T.length;
let P=S+"#"+T;
let p=P.length;

z=new Array();
l=0;
r=0;
for(let j=0;j<p;j++){
    z[j]=0;
}
for(let j=1;j<p;j++){
    if(j<=r){
        z[j]=Math.min(r-j+1,z[j-l]);
    }
    while(j+z[j]<p &&P.charAt(z[j])==P.charAt(j+z[j])){
        ++z[j];
    }
    if(j+z[j]-1>r){
        l=j;
        r=j+z[j]-1;
    }
    if(z[j]==m){
        console.log(j-m-1);
    }
}

console.log("It was Z-func")
console.log(" ")


pi=new Array;
pi[0]=0;
let k=0;
for(let i=1;i<=m;i++){
    while((k>0)&&(P.charAt(k)!=P.charAt(i))){
        k=pi[k-1];
    }
    if(P.charAt(k)==P.charAt(i)){
        k++;
    }
    pi[i]=k;


}
for(let i=m+1;i<P.length;i++){
    while((k>0)&&(P.charAt(k)!=P.charAt(i))){
        k=pi[k-1];
    }
    if(P.charAt(k)==P.charAt(i)){
        k++;
    }
    if(k==m){
        console.log(i-2*m);
    }
}

console.log("It was Prefix-func")
console.log(" ")



pre=new Array();
pre[0]=0;
k=0;
for(i=1;i <m;i++) {
    while((k>0) && (S.charAt(k)!=S.charAt(i))){
        k=pre[k-1];
    }
    if (S.charAt(k)== S.charAt(i))
        k++;
    pre[i]=k;
}
let k1=0;
let i1 = 0;
k=0
for(let i=0;i<n;i++){
    while((k>0)&&(S.charAt(k)!=T.charAt(i))){
        k=pi[k-1];
    }
    if(S.charAt(k)==T.charAt(i)){
        k++;
    }
    if(k==m){
        console.log(i-m + 1);
        k=0
    }
}
console.log("It was MorrisPratt-func")
console.log(" ")




let indexes = [];
let alphabet=[];
for (let i = 0; i < m; i++){
    alphabet[S.charAt(i)] = 0;
}
let delta = Array.from(Array(m + 1), () => []);
for (let i in alphabet) delta[0][i] = 0;
for (let i = 0; i < m; i++) {
    let prev = delta[i][S.charAt(i)];
    delta[i][S.charAt(i)] = i + 1;
    for (let j in alphabet) delta[i + 1][j] = delta[prev][j];
}

for (let i = 0, condition = 0; i < n; i++) {
    condition = delta[condition][T.charAt(i)];
    if (condition === undefined){
        condition = 0;
    }
    if (condition === m){
        indexes.push(i - m + 1);
    }
}

console.log(indexes);
console.log("It was Auto-func")
console.log(" ")
