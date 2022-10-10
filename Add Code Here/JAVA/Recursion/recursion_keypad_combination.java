public class recursion_keypad_combination {
    public static String keypad[] = {".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    public static void printCombinations(String str, int index, String combinations  ){
        if(index == str.length()){
            System.out.println(combinations);
            return;
        }
        char currentChar = str.charAt(index);
        String reqString = keypad[currentChar - '0'];
        int strLength = keypad[currentChar - '0'].length();
        for(int i=0;i<strLength;i++){
            printCombinations(str, index+1, combinations+reqString.charAt(i));
        }
    }
    public static void main(String[] args) {
        printCombinations("62", 0, "");
    }
}
