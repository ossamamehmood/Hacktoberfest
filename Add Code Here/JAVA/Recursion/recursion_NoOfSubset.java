
import java.util.*;

public class recursion_NoOfSubset {

    public static void PrintSubset(ArrayList <Integer> Subset){
        for(int i=0;i<Subset.size();i++){
            System.out.print(Subset.get(i)+" ");
        }
    }

    public static void FindSubset(int n,ArrayList<Integer> Subset){
        if(n==0){
            PrintSubset(Subset);
            System.out.println();
            return;
        }
        
        //comming
        Subset.add(n);
        FindSubset(n-1, Subset);

        //not comming
        Subset.remove(Subset.size()-1);
        FindSubset(n-1, Subset);
    }
    public static void main(String[] args) {
        ArrayList <Integer> Subset = new ArrayList<>();
        FindSubset(3, Subset);
    }
}
