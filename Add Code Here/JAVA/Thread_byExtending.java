class Mythread1 extends Thread
{
    public void run()
    {
        for (int i = 0; i < 5; i++) {
            System.out.println("My Thread1 is running");
        }
    }
}
class Mythread2 extends Thread
{
    public void run()
    {
        for (int i = 0; i < 5; i++) {
            System.out.println("My Thread2 is running");
        }
    }
}

public class Thread_byExtending {
    public static void main(String[] args) {
        Mythread1 t1 = new Mythread1();
        Mythread2 t2 = new Mythread2();
        t1.run();
        t2.run();
        System.out.println("hello");
    }
}
