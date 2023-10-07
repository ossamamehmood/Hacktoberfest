public class Multiple_Inheritance {
    public static void main(String[] args) {
     c obj = new c();
     obj.show();
     
    }
}

class A{
   public void show(){
    System.out.println("I am something needs to be printed!");
   } 
}

class B extends A{
  public void show(){
    System.out.println("I am something needs to be printed!");
  }
}

class c extends B{
    public void show(){
        System.out.println(" I am something needs to be printed!");
    }
}
