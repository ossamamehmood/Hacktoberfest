package tryyy;
import java.util.*;
public class KadaneAlgo {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int i,sum=0,maxsum=0,n=sc.nextInt();
        int[] a=new int[n];
        for(i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
            sum=sum+a[i];
            if(sum>maxsum)
                maxsum=sum;
            if(sum<0)
                sum=0;
        }
        System.out.println(maxsum);
    }
}
