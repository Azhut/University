const readline = require('readline').createInterface({
input: process.stdin, output: process.stdout})

function Incode(string, CodeOfChar){
    var res = "";
    for(i = 0; i < string.length; i++){
        res += CodeOfChar[string.charAt(i)];
    }
    return res;
}

function Decode(code, CharFromCode){
    var acc = "";
    var res = "";
    var i = 0;
    for(i = 0; i < code.length; i++){
        acc += code.charAt(i);
        if (acc in CharFromCode){
            res += CharFromCode[acc];
            acc = "";
        }
    }
    //if(acc) console.log("Код не соответствует алфавиту");
    return res;
}


function forest(wes, root) {
    this.wes=wes
    this.root=root
}


function tree (lson, rson,parent, stroca) {
    this.lson=lson
    this.rson=rson
    this.parent=parent
    this.stroca=stroca
}

readline.question("Введите текст: ", (str) => {
    let total_chars = 0;
    let alph = new Array();
    let ch;
    for (let i = 0; i < str.length; i++) {
        total_chars++;
        ch = str.charAt(i);
        if (alph[ch]) alph[ch]++;
        else alph[ch] = 1;
    }

    let diff_chars = 0;
    let NodeList = new Array();
    let NodeListTop = 0;
    let Queue = new Array();
    let QueueTop = 0;


    for (ch in alph) {
        diff_chars++;
        console.log(ch,'-',alph[ch])
        NodeList[NodeListTop++] = new tree(0,0,0,ch);
        Queue[QueueTop] = new forest(QueueTop++,alph[ch]);
    }

    let smalest1, smalest2;

    while(QueueTop >= 2){

        if(Queue[0].root < Queue[1].root) {smalest1 = 0; smalest2 = 1;}
        else {smalest1 = 1; smalest2 = 0;}
        for(i = 2; i < QueueTop; i++){
            if (Queue[i].root < Queue[smalest2].root){
                if(Queue[i].root < Queue[smalest1].root){
                    smalest2 = smalest1;
                    smalest1 = i;
                }
                else smalest2 = i;
            }
        }
        Node1 = Queue[smalest1].wes;
        Node2 = Queue[smalest2].wes;


        NodeList[NodeListTop++] = new tree(Node1, Node2, 0, NodeList[Node1].stroca + NodeList[Node2].stroca)

        NodeList[Node1].parent = NodeListTop - 1;
        NodeList[Node2].parent = NodeListTop - 1;


        Queue[smalest1].root = Queue[smalest1].root + Queue[smalest2].root;
        Queue[smalest1].wes = NodeListTop - 1;
        Queue[smalest2] = Queue[--QueueTop];
    }


    let CodeOfChar = new Array();
    let CharFromCode = new Array();
    console.log("Код каждой буквы: ")
    for(i = 0; i < diff_chars; i++){
        root_index = i; el_index = i;
        let code = "";
        while(NodeList[el_index].parent) {
            root_index = NodeList[root_index].parent;
            if (NodeList[root_index].lson === el_index) code = "0"+code;
            else code = "1"+code;
            el_index = root_index;
        }
        console.log(NodeList[i].stroca,':', code);
        CodeOfChar[NodeList[i].stroca] = code;
        CharFromCode[code] = NodeList[i].stroca;
    }

    console.log("Закодированный текст: ");
    console.log(Incode(str, CodeOfChar));


    readline.question("\nЗашифрованное сообщение: ", (code) => {
        readline.close();

        console.log("Расшифрованное сообщение: ",Decode(code,CharFromCode))
    });
});

