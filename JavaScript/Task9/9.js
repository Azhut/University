let readline = require('readline');
const erl = readline.createInterface({
    input: process.stdin,
    output: process.stdout

});
erl.question ('Ввод', (answer) =>  {
    erl.close();
    let str = answer;
    console.log(str);
    n=0
    let alphCh = new Array();
    for (i=0; i<str.length;i++) {
        if (alphCh[str.charAt(i)]) {
            alphCh[str.charAt(i)]++;
        } else {
            alphCh[str.charAt(i)] = 1;
            n++
        }
    }
    let h=0;
    if (n==1){
        console.log(h)
    } else {
        for(a in alphCh) {
            console.log(a, alphCh[a])
            let p = (alphCh[a])/(str.length);
            h=h-p*(Math.log(p)/Math.log(n));
        }
        console.log(h);
    }
});
