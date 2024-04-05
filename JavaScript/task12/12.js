const readline = require('readline').createInterface({
    input: process.stdin, output: process.stdout})

function CreateNode (Lbranch, Rbranch,root, weight, start, end, code, depth) {
    this.Lbranch=Lbranch;
    this.Rbranch=Rbranch;
    this.root=root
    this.weight= weight;
    this.start = start;
    this.end = end;
    this.code = code;
    this.depth=depth;
}

function CreateBranches(Node_idx){
    const Node=NodeList[Node_idx];

    //вывод строющевося дерева в консоль (нужно переработать)
    console.log("  ".repeat(Node.depth), alphabet.slice(Node.start, Node.end), Node.weight);

    //проверка на количество букв в узле. В случеае 1 буквы не создаём дочерние узлы, а запоминаем коды сиволов
    if (Node.end - Node.start === 1){
        CharFromCode[Node.code] = alphabet[Node.start]
        CodeOfChar[alphabet[Node.start]] = Node.code
        return;
    }

    //делим буквы на два равных подмножестав
    let Left_sum = 0;//Right_sum = Node.weight - Left_sum
    let sep = Node.start;
    while(Node.weight > 2*Left_sum + alphWeights[alphabet[sep]]){
        Left_sum += alphWeights[alphabet[sep]];
        sep++;
    }
    //создаём дочернии узлы
    Node.Lbranch = NodeListTop+1;
    Node.Rbranch = NodeListTop+2;
    NodeList[Node.Lbranch] = new CreateNode(0,0,Node_idx, Left_sum, Node.start, sep, Node.code + "0", Node.depth + 1);
    NodeList[Node.Rbranch] = new CreateNode(0,0,Node_idx, Node.weight - Left_sum, sep, Node.end,Node.code + "1", Node.depth + 1);
    NodeListTop += 2;

    //вызываем деление дочерних узлов
    CreateBranches(Node.Lbranch);
    CreateBranches(Node.Rbranch);
}

function Encode(string, CodeOfChar){
    let res = "";
    for(let i = 0; i < string.length; i++){
        res += CodeOfChar[string.charAt(i)];
    }
    return res;
}

function Decode(code, CharFromCode){
    let acc = "";
    let res = "";
    for(let i = 0; i < code.length; i++){
        acc += code.charAt(i);
        if (acc in CharFromCode){
            res += CharFromCode[acc];
            acc = "";
        }
    }
    //if(acc) console.log("can't decode properly");
    return res;
}

readline.question("Введите текст: ", (str) => {
    let total_chars = 0;
    let diff_chars = 0;
     alphabet = ""
     alphWeights = new Array();
    let ch;
    //считывание ввода и заполнение алфавита
    for (let i = 0; i < str.length; i++) {
        total_chars++;
        ch = str.charAt(i);
        if (alphWeights[ch]) alphWeights[ch]++;
        else {
            alphWeights[ch] = 1;
            alphabet += ch;
            diff_chars++;
        }
    }

    console.log("Частота каждого символа: ")
    for (ch in alphWeights) {
        console.log(ch,'-',alphWeights[ch])
    }

    NodeList = new Array();//список всех узлов дерева
    NodeListTop = 0;

    CodeOfChar = new Array();
    CharFromCode = new Array();

    NodeList[0] = new CreateNode(0,0,0, total_chars, 0, alphabet.length, "", 0);
    console.log("\nПостроение дерева: ")
    CreateBranches(0);


    //вывод кодов символов
    console.log("\nКод каждого символа: ")
    for(let i = 0; i < diff_chars; i++){
        console.log(alphabet.charAt(i),':', CodeOfChar[alphabet.charAt(i)])
    }

    //вывод закодированного сообщения

    console.log("Закодированное сообщение: ")
    console.log(Encode(str, CodeOfChar));

    //вводи и декодирование второго сообщения
    readline.question("\nВведите закодированное сообщение: ", (code) => {
        readline.close();

        console.log("\nРаскодированное сообщение: ", Decode(code,CharFromCode))

    });
});