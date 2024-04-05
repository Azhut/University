function Triangle(side1, side2,side3) {
    this.side1 = side1;
    this.side2 = side2;
    this.side3 = side3;

    this.Perimetr = function Perimetr(){
        return this.side1+this.side2+this.side3;
    }

    this.Square = function Square(){
        return Math.sqrt((this.Perimetr()/2*(this.Perimetr()/2-side1)*(this.Perimetr()/2-side2)*(this.Perimetr()/2-side3)))
    }

    this.Radius = function Radius(){
        return (2*this.Square())/(this.Perimetr())
    }
}

Triangle1 =new Triangle(3,6,5);

console.log(Triangle1.Perimetr())
console.log(Triangle1.Square())
console.log(Triangle1.Radius())