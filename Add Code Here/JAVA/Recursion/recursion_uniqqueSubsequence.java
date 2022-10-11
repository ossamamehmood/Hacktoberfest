import java.util.HashSet;

public class recursion_uniqqueSubsequence {
    public static void printSubsequence(String str , int index, String newString,HashSet<String> set){
        if(index == str.length()){
            if(set.contains(newString)){
                return;
            }else{
            System.out.println(newString);
            set.add(newString);
            return;
            }
        }
        char currentChar = str.charAt(index);
        // to add
        printSubsequence(str, index+1, newString+currentChar, set);
        //not to add
        printSubsequence(str, index+1, newString, set);
    }
    public static void main(String[] args) {
        String str = "abc";
        HashSet<String> set = new HashSet<>();
        printSubsequence(str, 0, "", set);
    }
}
