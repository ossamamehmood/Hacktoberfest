package shape;

public class Sphere extends shape{

    Sphere(int dim1,int dim2){
        super(dim1, dim2);
    }

    public double area(){
        return (4 * Math.PI * this.dim1 * this.dim1);
    }
}

