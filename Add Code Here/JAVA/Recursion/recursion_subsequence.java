public class recursion_subsequence {
    public static void printSubsequence(String str , int index, String newString){
        if(index == str.length()){
            System.out.println(newString);
            return;
        }
        char currentChar = str.charAt(index);
        // to add
        printSubsequence(str, index+1, newString+currentChar);
        //not to add
        printSubsequence(str, index+1, newString);
    }
    public static void main(String[] args) {
        String str = "abc";
        printSubsequence(str, 0, "");
    }
}
