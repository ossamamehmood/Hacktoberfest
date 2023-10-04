
public class Super {
    public static void main(String[] args) {
        B onj2 = new B();
        onj2.show();
    }
}


class A{
    int i;
    public void show(){
      System.out.println("I am in class A");
    }
}

class B extends A{
    @overide 
    public void show(){
        super.show();
        super.i = 30;
        System.out.println(i);
        System.out.println("I am in class B");
      }
}
