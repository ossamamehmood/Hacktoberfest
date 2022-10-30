package shape;

public class shape {
   
    int dim1,dim2;
    shape(int dim1,int dim2){
        this.dim1 = dim1;
        this.dim2 = dim2;
    }

    public int getdim1(){
        return this.dim1;
    }
    
    public int getdim2(){
        return this.dim2;
    }

    public void setdim1(int dim1){
        this.dim1 = dim1;
    }

    public void setdim2(int dim2){
        this.dim2 = dim2;
    }
}
