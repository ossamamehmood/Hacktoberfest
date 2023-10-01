package Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MedianSortedArrays {
    public static double median(List<Integer> a, List<Integer> b, int n1,int n2){
        if(n1>n2){
            return median(b,a,n2,n1);
        }
        int low = 0, high  = n1;

        while(low <= high){
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2)/2 - cut1;

            int l1 = cut1 == 0?Integer.MIN_VALUE:a.get(cut1-1);

            int l2 = cut2 == 0?Integer.MIN_VALUE:b.get(cut2-1);
            int r1 = cut1 == n1?Integer.MAX_VALUE:a.get(cut1);
            int r2 = cut2 == n2? Integer.MAX_VALUE:b.get(cut2);

            if(l1>r2){

                high = cut1-1;
            }
            else if(l2>r1){

                low = cut1+1;
            }
            else{
                if((n1+n2)%2 == 0){
                    return ((double)(Math.max(l1,l2) + Math.min(r1,r2))/2);
                }
                return (double)(Integer.min(r1,r2));
            }
        }
        return (double)0;

    }

    public static void main(String[] args) {
       List<Integer> a = Arrays.asList(1,5,8,10,12,18);
       List<Integer> b = Arrays.asList(2,3,6,7);

        System.out.println(median(a,b,a.size(),b.size()));
    }

}
