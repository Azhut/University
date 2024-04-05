let readline = require('readline'); 
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
rl.question('Ввод ', (answer) => {
    let str = answer;
    console.log(str);
	n=0
	let alphch=new Array();
	for(i=0;i<str.length;i++) {
		if (alphch[str.charAt(i)]) {
			alphch[str.charAt(i)]++;
		} else {
			alphch[str.charAt(i)]=1;
			n++
		}
	}
	let bit = Math.ceil(Math.log(n) / Math.log(2))
	console.log(bit);
	let counter = 0;
	let zero='0';
	for(a in alphch){
		alphch[a] = zero.repeat(bit - counter.toString(2).length) + counter.toString(2);
		counter ++
	}
	for(a in alphch){
			console.log(a, alphch[a]);
	}
	let new_str='';
	for (i=0;i<str.length;i++) {
		new_str += alphch[str.charAt(i)];
	}
	console.log(new_str);


rl.question('Ввод', (answer2) => {
	rl.close();
	let outp1 = answer2;
	console.log(outp1);
	
	let prom='';
	let new_str1='';
	let i = 0;
	while (i < outp1.length +1) {
		prom = outp1.slice(i, i+bit);
		for (a in alphch){
			if (alphch[a] == prom){
				new_str1 += a;
				break
			}
		}
		i = i + bit;
	}
	console.log(new_str1);
	});
});