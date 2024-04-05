//создать два текстовых файла file.txt и code.txt и куазать путь к ним в path
//вызывать скрипт через косоль командой Cscript <path>\encoder.js
path='E:\\homework_folder\\»“и—\\task3'
fso = new ActiveXObject("Scripting.FileSystemObject")
fh = fso.OpenTextFile(path+"\\file.txt")
file=fh.ReadAll()
fh.Close()

var asciilenth=Math.pow(2,7)
var LastChar=''
var Count=0
var code=''

for(i=0;i<=file.length;i++){
	CurChar=file.charAt(i)
	if(CurChar==LastChar){Count++;continue}
	
	CountShift=(LastChar!='#')?(4):(1);claster=''
	claster+=Array(1+Math.floor(Count/(asciilenth+CountShift-1))).join(('#'+String.fromCharCode(127)+LastChar))
	if ((remaind=Count%(asciilenth+CountShift-1))>(CountShift-1)){claster+='#'+String.fromCharCode((remaind-CountShift))+LastChar}
	else{claster+=Array(1+remaind).join(LastChar)}
	
	WSH.echo(Count+LastChar+'=>'+claster)
	
	code+=claster
	LastChar=CurChar
	Count=1
}
fh = fso.OpenTextFile(path+"\\code.txt",2,true)
fh.WriteLine(code)
fh.close()
WSH.echo('\n'+code)
