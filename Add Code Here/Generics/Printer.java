class Printer<T>{
    T a;
    public Printer(T a){
        this.a = a;
    }
    public void display(){
        System.out.println("The value of a : "+a);
    }
}