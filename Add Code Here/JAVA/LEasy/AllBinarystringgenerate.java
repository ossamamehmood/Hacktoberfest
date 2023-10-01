package LEasy;

import java.util.ArrayList;
import java.util.List;

public class AllBinarystringgenerate {
    public static void main(String[] args) {

        int n=3;

        generateBins(n);





    }

    private static void generateBins(int n) {

        List<String > ls= new ArrayList<>();
        generatebinshelper(n,"",ls);
        System.out.println(ls);
    }
    private static void generatebinshelper(int n, String str,List<String> ls) {


        if(n==0){
            ls.add(str);
            return;
        }
        generatebinshelper(n-1,str+"O",ls);
        if(str.isEmpty() || str.charAt(str.length()-1)=='O'){
            generatebinshelper(n-1,str+"1",ls);
        }
    }
}
