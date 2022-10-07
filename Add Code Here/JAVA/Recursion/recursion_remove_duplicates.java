public class recursion_remove_duplicates {
    static boolean [] map = new boolean[26];

    public static void removeDuplicates(String str, int index, String newString){
        if(index == str.length()){
            System.out.println("the new string after removal of duplicates is "+newString);
            return;
        }
        
        
        char currentChar = str.charAt(index);

        if(map[currentChar - 'a'] == true){
            removeDuplicates(str, index+1, newString);
        }else{
            newString+=currentChar;
            map[currentChar - 'a']=true;
            removeDuplicates(str, index+1, newString);
        }
    }
    public static void main(String[] args) {
        String str = "abcddcbaxxyyz";
        removeDuplicates(str, 0, "");
    }
}
