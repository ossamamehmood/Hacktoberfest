public class Multiple_inheritance_with_interfaces {
    public static void main(String[] args) {
        
    }
}

interface A{
    default void show(){
        System.out.println("In interface A");
    }
}

interface B{
    default void show(){
      System.out.println("In interface B");
    }
}

class i implements A,B{
    public void message(){
        System.out.println("I am in the message class");
    }
    // public void show(){
    //     System.out.println("I am in the class i now");
    // }
    
    public void show(){
        A.super.show();
    }
    
}
