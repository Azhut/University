var a = prompt('a', '');
var b = prompt('b', '');
var c = prompt('c', '');
var d = b*b-4*a*c;
var t;
var x1;
var x2;
if (d>=0) {
	t = true;
	x1 =((-b+Math.sqrt(d))/(2*a));
	x2 =((-b-Math.sqrt(d))/(2*a));
} else {
	t=false;
}
alert(t +' '+ x1 + ' ' + x2);
