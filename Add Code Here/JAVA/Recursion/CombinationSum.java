
import java.util.*;
public class R_Combination1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        ArrayList<Integer> a=new ArrayList<>();
        int[] arr={2,3,6,7};
        int target=7;
       combination(0,target,arr,a);
    }
    public static void combination(int i, int sum,int[] arr, ArrayList<Integer> a)
    {
        if(i==arr.length)
        {if(sum==0)
            System.out.println(a);
            return;
        }

        if(arr[i]<=sum)
        {
            a.add(arr[i]);
            combination(i,sum-arr[i],arr,a);
            a.remove(a.size()-1);
        }
        combination(i+1,sum,arr,a);
    }
}
