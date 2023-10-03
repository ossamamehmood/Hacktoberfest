public class Abstract {
    public static void main(String[] args) {
        Human obj1 = new Man();
        obj1.walk();
    }
}

abstract class Human{

    public abstract void eat();

    public void walk(){
        System.out.println("He can walk");
    }
}

class Man extends Human{
  public void eat(){
    System.out.println("I can eat also");
  }
}
