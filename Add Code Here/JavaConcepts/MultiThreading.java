public class MultiThreading {
    public static void main(String[] args) {
        hii hi = new hii();
        hello hel = new hello();
        hi.start();
        try{Thread.sleep(10);}catch(Exception e){};
        hel.start();
    }
}


class hii extends Thread{
    public void run(){
        for (int i = 0; i < 5; i++) {
            System.out.println("Hii");
            try{Thread.sleep(1000);}catch(Exception e){};
        }
       
        
    }
}

class hello extends Thread{
    public void run(){
        for (int i = 0; i < 5; i++) {
            System.out.println("Hello");
            try{Thread.sleep(1000);}catch(Exception e){};
        }
        
        
    }
}