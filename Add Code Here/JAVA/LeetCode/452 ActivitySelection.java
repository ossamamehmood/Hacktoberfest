import java.util.ArrayList;

public class ActivitySelection{

    static void find(int start[], int end[]){  // O(n)

        ArrayList<String> list = new ArrayList<>();
        int prev = -1;

        for(int i=0; i<end.length; i++){
            if(start[i]>=prev){
                list.add("A"+i);
                prev = end[i];
            }
        }

        for(String a : list)
        System.out.print(a+" ");
    }


    public static void main(String[] args) {
        int start[] = {10, 12, 20};
        int end[] = {20, 25, 30};

        find(start,end);
    }
}