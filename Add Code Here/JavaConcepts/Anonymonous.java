public class Anonymonous{
    public static void main(String[] args) {
        A obj = new A(){
            public void show(){
                System.out.println("I am the best");
            }
        };

     obj.show();
    }
} 

class A{
    public void show(){
        System.out.println("I am in the class A");
    }
}

// class B extends A{
//    public void show(){
//     System.out.println("I am in now the class B");
//    }
// }