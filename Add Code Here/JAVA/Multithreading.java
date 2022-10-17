// Multithreading in Java is a process of executing multiple threads simultaneously.
// We can perform many operations together, so it saves time.


//Thread creation can be done by extending the Thread Class.


class MultiThreading extends Thread {

    public void run() {
        try {
            System.out.println("Thread " + Thread.currentThread().getId() + " is running");
        } catch (Exception err) {
            // Throwing an exception
            System.out.println("Exception is caught");
        }
    }
}


public class Multithread {
    public static void main(String[] args)
    {
        int n = 5; 
        for (int i = 0; i < n; i++) {
            MultiThreading object
                = new MultiThreading();
            object.start();
        }
    }
}
