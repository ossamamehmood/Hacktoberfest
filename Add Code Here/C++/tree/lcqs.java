import java.io.*;
import java.util.*;

public class Main{

public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int n1 = scn.nextInt();
    int []  arr1 = new int [n1];
    for(int i =0;i<arr1.length;i++){
        arr1[i]=scn.nextInt();
    }
    
    HashMap<Integer,Boolean> h  = new HashMap();
    
    for(int j = 0 ;j<arr1.length ; j++){
        int a = arr1[j];
        h.put(a,false);
    }
    
    for(int k = 0;k<arr1.length;k++){
        int b = arr1[k];
        if(h.containsKey(b-1)){
            continue;
        }else{
            h.put(b,true);
        }
    }
    int count =0;
    int start =0;
    for(Integer  f : h.keySet()){
        if(h.containsKey(f)==true){
            int count1 =1;
            int e=f;
            while(h.containsKey(f+1)){
                count1++;
                f=f+1;
            }
            if(count<count1){
                count=count1;
                start=e;
            }
            
        }
    }
    for(int l = 0;l<count;l++){
        System.out.println(start);
        start=start+1;
    }
    
 }

}
