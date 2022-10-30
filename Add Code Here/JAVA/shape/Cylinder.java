package shape;

public class Cylinder extends shape{

    Cylinder(int dim1,int dim2){
        super(dim1, dim2);
    }

    public double area(){
        return (2 * Math.PI * this.dim1 * (this.dim2 + this.dim1));
    }
}

