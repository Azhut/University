

function RobinKarp(S,T){

	var n = S.length;
	var m = T.length;
	var ht=0;
	var hs=0;
	var k = m-1;
	var st2 = 1
	ans=[]
	while (k>=0){
		ht += T.charCodeAt(k) * st2;
		hs += S.charCodeAt(k) * st2;
		k = k-1;
		st2 = st2 * 2;
	}
	st2 = st2 / 2;
	let i=0;
	while (i<n-m){
		if(hs==ht){
			j=0;
			while (S.charCodeAt(i+j)==T.charCodeAt(j) && j<m) {
			 j++;
			}
			if (j==m){
		   ans.push(i);
		}
		}
		i++;
		
		if (i<= n-m){
		hs=(hs - S.charCodeAt(i-1) * st2) * 2 + S.charCodeAt(i+m-1);
		}
		

	}
	return ans;

}

function Hash(S,T){
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

function BruteForce(S,T){
    ans=[]
    n=S.length;
    m=T.length;
    for(i=0; i<=n-m ; i++){
        g=0;
        while((T.charAt(g)==S.charAt(g+i))&&(g<m)){g++;}
        if (g==m){
            ans.push(i);
        }
    }
    return ans
}

function MorissPratt(T,S) {
	let m = S.length;
	let n = T.length;
	let P = S + "#" + T;
	let p = P.length;
	ans=[];

	pi = new Array;
	pi[0] = 0;
	let k = 0;
	for (let i = 1; i <= m; i++) {
		while ((k > 0) && (P.charAt(k) != P.charAt(i))) {
			k = pi[k - 1];
		}
		if (P.charAt(k) == P.charAt(i)) {
			k++;
		}
		pi[i] = k;
	}


	pre = new Array();
	pre[0] = 0;
	k = 0;
	for (i = 1; i < m; i++) {
		while ((k > 0) && (S.charAt(k) != S.charAt(i))) {
			k = pre[k - 1];
		}
		if (S.charAt(k) == S.charAt(i))
			k++;
		pre[i] = k;
	}
	let k1 = 0;
	let i1 = 0;
	k = 0
	for (let i = 0; i < n; i++) {
		while ((k > 0) && (S.charAt(k) != T.charAt(i))) {
			k = pi[k - 1];
		}
		if (S.charAt(k) == T.charAt(i)) {
			k++;
		}
		if (k == m) {
			ans.push(i - m + 1);
			k = 0
		}
	}
	return ans;
}

function automat(T,S) {
	let m = S.length;
	let n = T.length;
	let P = S + "#" + T;
	let p = P.length;
	let indexes = [];
	let alphabet = [];
	for (let i = 0; i < m; i++) {
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
		if (condition === undefined) {
			condition = 0;
		}
		if (condition === m) {
			indexes.push(i - m + 1);
		}
	}
	return indexes;
}

function ShiftsTable(string) {
		var res = new Array(256);
		res.fill(string.length);

		for (let i = string.length - 2; i >= 0; --i) {
			let index = string.charCodeAt(i);
			if (res[index] == string.length) {
				res[index] = string.length - i - 1;
			}
		}

		return res;
	}

function SuffixShiftsTable(string) {
	suffshift = new Array();
	z = new Array();

	m = string.length;
	maxZidx = 0;
	maxZ = 0;

	for (var j = 0; j <= m; j++) {
		z[j] = 0
		suffshift[j] = m
	}

	for (var j = 1; j < m; j++) {
		if (j <= maxZ) z[j] = Math.min(maxZ - j + 1, z[j - maxZidx]);
		while (j + z[j] < m && string.charCodeAt(m - 1 - z[j]) == string.charCodeAt(m - 1 - (j + z[j]))) z[j]++;
		if (j + z[j] - 1 > maxZ) {
			maxZidx = j;
			maxZ = j + z[j] - 1;
		}
	}

	for (var j = m - 1; j > 0; j--) suffshift[m - z[j]] = j;
	for (var j = 1; j <= m - 1; j++) {
		if ((j + z[j]) == m) {
			for(var r = 0; r <= j; r++) {
				if (suffshift[r] == m) suffshift[r] = j;
			}
		}
	}

	return suffshift;
}

function StopTable(string) {
	var res = new Array(256);
	res.fill(-1);

	for (let i = string.length - 2; i >= 0; --i) {
		let index = string.charCodeAt(i)-971;
		if (res[index] == -1) {
			res[index] = i;
		}
	}

	return res;
}

function BMHorspul(seq, subseq) {
	let N = []
	let indexes = [];


	for (let i = 0; i<T.length-1; i++){
		N[T.charAt(i)] = i + 1;
	}

	for (let i = 0; i <= S.length - T.length;) {
		let j = T.length - 2, length = 0;
		for (; j >= 0 && S[i + j] === T[j]; j--) length++
		if (j < 0) indexes.push(i+1)
		let char = S.charAt(i+T.length-1);
		if (!N[char]) i += T.length
		else i += T.length-N[char];
	}
	console.log(indexes);
	}

function BM(T, S) {
	n = T.length ;
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

	N = new Array()
	for(j=0;j<S.length-1;j++)
		N[S.charAt(j)]=j+1


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
				StopTable = N[T.charAt(i + j)];
			}
			else{
				StopTable = 0;
			}
			i = Math.max(i + suffshift[j+1], i + j + 1 - StopTable);
		}

	}
}






/*const fs = require("fs");
const s = fs.readFileSync('input2.txt', 'utf8');
let S = s.split('\n')[0];
let T = s.split('\n')[1];*/




const fs = require("fs");
const s = fs.readFileSync('input2.txt', 'utf8');
let S = fs.readFileSync('Chto_skazal_pokoinik.txt', 'utf8');
let T = fs.readFileSync('substr.txt', 'utf8');





//BruteForce
let BFstart = new Date();
BruteForce(S,T);
 let BFfinish = new Date();
 let BFdiff = BFfinish - BFstart;
console.log("Time of BruteeForce working: ", BFdiff, BruteForce(S,T));


//Hash
 let Hashstart = new Date();
Hash(S,T);
 let Hashfinish = new Date();
 let Hashdiff = Hashfinish - Hashstart;
console.log("Time of Hash working: ", Hashdiff, Hash(S,T));

//Robin
 let Robinstart = new Date();
RobinKarp(S,T);
 let Robinfinish = new Date();
 let Robindiff = Robinfinish - Robinstart;
console.log("Time of Rabin-Karp working: ", Robindiff,RobinKarp(S,T));

//MorrisPratt
 let MorrisPrattstart = new Date();
MorissPratt(S,T);
 let MorrisPrattfinish = new Date();
 let MorrisPrattdiff = MorrisPrattfinish - MorrisPrattstart;
 console.log("Time of MorrisPratt working: ", MorrisPrattdiff,MorissPratt(S,T));
 
//Automat
 let Autostart = new Date();
automat(S,T);
 let Autofinish = new Date();
 let Autodiff = Autofinish - Autostart;
console.log("Time of Automat working: ", Autodiff,automat(S,T));

//BMH
 let BMHstart = new Date();
BMHorspul(S,T);
 let BMHfinish = new Date();
 let BMHdiff = BMHfinish - BMHstart;
console.log("Time of  Boyer-Moore-Horspool working: ", BMHdiff);
BMHorspul(S,T);


//BM
let BMstart = new Date();
BM(S,T);
let BMfinish = new Date();
let BMdiff = BMfinish - BMstart;
console.log("Time of  Boyer-Moore working: ", BMdiff);


