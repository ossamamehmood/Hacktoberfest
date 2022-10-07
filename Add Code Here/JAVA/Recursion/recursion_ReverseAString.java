public class recursion_ReverseAString {
    static int first = -1;
    static int last = -1;
    public static void reverseStr(String str, int index,char character){

        if(index==str.length()){
            System.out.println("first occurance at index "+first);
            System.out.println("last occurance at index "+last);
            return;
        }
        char currentChar = str.charAt(index);
        if(currentChar == character){
            if(first == -1){
                first = index;
                last = index;
            }
            else{
                last = index;
            }
        }
        reverseStr(str, index+1, character);
    }
    public static void main(String[] args) {
        String s1 = "abddhjfjfjjfjjfjf";
        System.out.println(s1.length());
        reverseStr(s1, 0, 'a');
    }
}
