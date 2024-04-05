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

function BMHorspul(seq, subseq) {
    var res = new Array();
    var table = ShiftsTable(subseq);

    var i = 0;
    while (i < seq.length - subseq.length ) {
        let j = subseq.length - 1;
        while (j >= 0 && subseq[j] == seq[i + j]) j--;
        if (j < 0) res.push(i);
        i += table[subseq.charCodeAt(Math.max(j, 0))];
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
        let index = string.charCodeAt(i);
        if (res[index] == -1) {
            res[index] = i;
        }
    }

    return res;
}

function BM(seq, subseq) {
    var res = new Array();
    var suffshift = SuffixShiftsTable(subseq);
    var stoptable = StopTable(subseq);

    var i = 0, j = 0;
    var bound = 0;
    while (i < seq.length - subseq.length) {
        j = subseq.length - 1;
        while (j >= bound && subseq[j] == seq[i + j]) j--;

        let tmp = ""
        for (let k = Math.max(j, 0); k < subseq.length; ++k) tmp += subseq[k];
        console.log(tmp);

        if (j < bound) {
            res.push(i);
            bound = subseq.length - suffshift[0];
            i += suffshift[0];
        } else {
            bound = 0;
            i = Math.max(i + suffshift[j + 1], i + j - stoptable[seq.charCodeAt(i + j)]);
        }
    }
    return res;
}

const fs = require("fs");
    var text = fs.readFileSync("input2.txt","utf8").split("\n")
console.log(text)
console.log("алгоритм Бойера—Мура—Хорспула: ",BMHorspul(text[0], text[1]));
console.log("алгоритм Бойера—Мура: ",BM(text[0], text[1]));
