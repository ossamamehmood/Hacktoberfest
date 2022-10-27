import java.util.ArrayList;

public class arraylistremoveduplicates {
    public static ArrayList<Integer> rd(int []arr){
        ArrayList<Integer> al=new ArrayList<>();
        al.add(arr[0]);
        for(int i=1;i<arr.length;i++){
            if(arr[i]!=arr[i-1]){
                al.add(arr[i]);
            }
        }
        return al;

    }
    public static void main(String[] args) {
        int arr[]={10,10,20,20,20,30,30,10};
        ArrayList<Integer> al=rd(arr);
        for(int i=0;i<al.size();i++){
            System.out.println(al.get(i));
        }

    }
}
