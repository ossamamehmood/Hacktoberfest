package LEasy;

import java.util.*;

public class Union {
    public static void main(String[] args) {
        int[] arr1={1,2,3,4,5,4};
        int[] arr2={1,2,3,4,6};

//        bruteforce(arr1,arr2);
        optimal(arr1,arr2);
        







    }

    private static void optimal(int[] arr1, int[] arr2) {
        ArrayList<Integer> ans=new ArrayList<>();

        int n1=arr1.length;
        int n2=arr2.length;
        int i=0,j=0;

        while (i<n1 && j<n2){

            if(arr1[i]<=arr2[i]){

                if(ans.size()==0 || ans.get(ans.size()-1)!=arr1[i]){
                    ans.add(arr1[i]);
                }
                i++;

            }else {

                    if(ans.size()==0 || ans.get(ans.size()-1)!=arr2[j]){
                        ans.add(arr2[j]);
                    }
                    j++;
            }
            while (j<n2){
                if(ans.size()==0 || ans.get(ans.size()-1)!=arr2[j]){
                    ans.add(arr2[j]);
                }
                j++;
            }

            while (i<n1){
                if(ans.size()==0 || ans.get(ans.size()-1)!=arr1[i]){
                    ans.add(arr1[i]);
                }
                i++;
            }

            System.out.println(ans);






        }













    }

    private static void bruteforce(int[] arr1, int[] arr2) {

        Set<Integer> s=new HashSet<>();

        for (int i = 0; i < arr1.length; i++) {
            s.add(arr1[i]);

        }
        for (int i = 0; i < arr2.length; i++) {
            s.add(arr2[i]);
        }

        List<Integer> ls=new ArrayList<>();

        Iterator<Integer> it = s.iterator();

        while (it.hasNext())
        {
            ls.add(it.next());
        }

//        System.out.println(ls);
//
//
//        for (int i:s) {
////            ls.add(i);
//            System.out.print(i+" ");
//        }


    }


}
