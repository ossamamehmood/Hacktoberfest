public class Thread_Naming {
    public static void main(String[] args) {
        Thread t1 = new Thread(()->{
            for (int i = 0; i < 5; i++) {
                System.out.println("Hii" + Thread.currentThread().getPriority());
                try{Thread.sleep(1000);}catch(Exception e){};
            }
        }, "Hii thread");

        Thread t2 = new Thread(()->{
            for (int i = 0; i < 5; i++) {
                System.out.println("Hello"+ Thread.currentThread().getPriority());
                try{Thread.sleep(1000);}catch(Exception e){};
            }
        }, "Hello thread");
        // t1.setName("Hii thread");
        // t2.setName("Hello Thread");


        // t1.setPriority(1);
        // t2.setPriority(10);

        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.MAX_PRIORITY);
        System.out.println(t1.getPriority());
        System.out.println(t2.getPriority());
        System.out.println(t1.getName());
        System.out.println(t2.getName());

    }
}
