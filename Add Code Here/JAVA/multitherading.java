
class Mytheread1 extends Thread{
    @Override
    public void run (){
        int i=0;
        while( i<40000){
        System.out.println("My therad is Running iam happy");
        System.out.println("iam happy");
        i++;
        }

    }

}
class Mytheread2 extends Thread{
    @Override
    public void run (){
        int i=0;
        while(i<40000){
        System.out.println("Therad 2 is good");
        System.out.println("iam sad");
        i++;
        }

    }

}





public class multitherading {
    public static void main(String[] args) {
        Mytheread1 t1=new Mytheread1();
        Mytheread2 t2=new Mytheread2();
        t1.start();
        t2.start();



        
    }
}
