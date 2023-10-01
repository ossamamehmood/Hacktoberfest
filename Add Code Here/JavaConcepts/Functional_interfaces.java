public class Functional_interfaces {
    public static void main(String[] args) {
        demo2 d = new Demo();
        d.display();
        d.show();

        dem d1 = ()-> System.out.println("I can be written like this");
        d1.fun();
    }
}

interface dem{
    void fun();
}
interface demo2{
    void show();

    default void display(){
        System.out.println("I am displaying my data into the file");
    }
}

class Demo implements demo2{
    public void show(){
        System.out.println("This is only to display the text or something");
    }

    // I can overide my method as well
    @overide
    public void display(){
        System.out.println("I am overiding my display method");
    }
}
