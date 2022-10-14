import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
       Scanner scan = new Scanner(System.in);
       
       int n = scan.nextInt();
       int t1d = scan.nextInt();
       int t2d = scan.nextInt();
       int t3d = scan.nextInt();
       
       toh(n,t1d,t2d,t3d);
    }

    public static void toh(int n, int t1id, int t2id, int t3id){
        
        if(n==0){
            return;
        }
        
         toh(n-1,t1id,t3id,t2id);
         System.out.println(n+"[" +t1id + " -> " + t2id + "]");
         toh(n-1,t3id,t2id,t1id);
        
    }

}
