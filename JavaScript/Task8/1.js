function Gruppa(n,spec,kolich) {
    this.n=n;
    this.spec=spec;
    this.kolich=kolich;


    this.add_stud=function add_stud(k) {
        this.kolich+=k;
        console.log('В группу ' + this.n + ' добавили '+ k + ' студентов.');
    }


    this.sub_stud = function sub_stud(k){
        this.kolich-=k;
        console.log('Из группы ' + this.n + ' исключили '+ k + ' студентов.');
    }
}


gr2 = new Gruppa(102,'КН',27);
gr3 = new Gruppa(103,'КН',25);
gr4 = new Gruppa(104,'КН',31);

//добавил вывел
gr2.sub_stud(15);
gr2.add_stud(3);
console.log(gr2.kolich);

gr3.add_stud(1);
gr3.sub_stud(8);
console.log(gr3.kolich);

gr4.add_stud(4);
gr4.sub_stud(3);
console.log(gr3.kolich);

