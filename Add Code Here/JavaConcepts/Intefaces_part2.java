public class Intefaces_part2 {
    public static void main(String[] args) {
        B obj = new B();
        obj.message();
    }
}

interface A{
    void show();
}

interface C{
    void message();
}

class B implements A, C{
    public void show(){
      System.out.println("I am in A");
    }

    public void message(){
        System.out.println("In the interface c");
    }
}


