public class Interfaces_with_Anonymous 
{
    public static void main(String[] args) {
        A obj = new A() {
            public void show(){
                System.out.println("I am the best");
            }
        };

        obj.show();
    }
    
}

interface A{
    void show();
}
