let menu = {
    width:200,
    height:300,
    title:"My menu"
}

function AddString(obj){
    for(el in obj) if(typeof obj[el] == "string") obj[el] += " Это строка";
}



function Log_obj(obj){
    for(var el in obj) console.log(obj[el]);
}

Log_obj(menu);
AddString(menu);
console.log("\nAfter the function\n")
Log_obj(menu);