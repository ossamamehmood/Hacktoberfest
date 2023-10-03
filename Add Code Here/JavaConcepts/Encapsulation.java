public class Encapsulation {
    public static void main(String[] args) {
        A obj1 = new A();
        obj1.setb(90);
        obj1.getb();
        obj1.show();    
        
    }
}

class A{
  int a;
  
  private  int b;
  

  public void geta(){
    System.out.println(a);
  }

  public void setb(int b){
    this.b = b;
  }
  public void getb(){
    System.out.println(b);
  }
    void show(){
        System.out.println("I am in class A");
    }
}
