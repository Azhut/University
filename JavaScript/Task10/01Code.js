let readline = require('readline');
const erl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
erl.question('Ввод на кодирование: ', (answer) => {
    let str = answer;
    n=0
    let Alphabet=new Array();
    for(i=0;i<str.length;i++) {
        if (Alphabet[str.charAt(i)]) {
            Alphabet[str.charAt(i)]++;
        } else {
            Alphabet[str.charAt(i)]=1;
            n++
        }
    }
    let bit = Math.ceil(Math.log(n) / Math.log(2))
    //console.log(bit,n);
    let counter = 0;
    let zero='0';
    for(a in Alphabet){
        Alphabet[a] = zero.repeat(bit - counter.toString(2).length) + counter.toString(2);
        counter ++
    }
    for(a in Alphabet){
        console.log(a, '-',Alphabet[a]);
    }
    let Answer='';
    for (i=0;i<str.length;i++) {
        Answer += Alphabet[str.charAt(i)];
    }
    console.log(Answer);
    console.log('')

erl.question('Ввод на декодирование: ', (answer2) => {
        erl.close();
        let str2 = answer2;
        let prom='';
        let Answer2='';
        let i = 0;

        while (i < str2.length +1) {
            prom = str2.slice(i, i+bit);
            for (a in Alphabet){
                if ( Alphabet[a] == prom){
                    Answer2 += a;
                    break
                }
            }
            i = i + bit;
        }
        console.log(Answer2);
    });
});