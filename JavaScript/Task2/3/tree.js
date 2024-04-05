var n = prompt('n', '');
var a, b = 0;

for(i = 0; true; ++i){
    a = "";
    for(j = 0; j < i; ++j){
        b++;
        a += b + " ";
        if(b + 1 > n) {
            break;
        }
    }
    console.log(a);
    if(b + 1 > n){
        break;
    }
}
 