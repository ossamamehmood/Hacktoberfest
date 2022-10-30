package shape;

public class Square extends shape{

    Square(int dim1){
        super(dim1,-1);
    }

    public int area(){
        return this.dim1 * this.dim1;
    }
}

