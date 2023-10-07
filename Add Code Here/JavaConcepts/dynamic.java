public class dynamic {
    public static void main(String[] args) {
        A obj1 = new B();
        
        obj1.show();
        obj1.fun();
        //obj1.fun2();
        obj1 = new C(); //dynamic dispatch
        obj1.fun();

    }
}

class A{
    public void show(){
        System.out.println("In class A");
    }

    public void fun(){
        System.out.println("Fun function in class A");
    }
}

class B extends A{
    public void show(){
        System.out.println("In class B");
    }
    public void fun2(){
        System.out.println("Fun function in class B");
    }
}

class C extends A{
    public void fun(){
        System.out.println("Fun function in class C");
    }
}


