public class Need_of_Abstract {
    public static void main(String[] args) {
        A obj = new A();
        obj.display(34.5);
        obj.display(23);
    }
}

class A{
    public void display(Number i){
        System.out.println(i);
      
    }
}
