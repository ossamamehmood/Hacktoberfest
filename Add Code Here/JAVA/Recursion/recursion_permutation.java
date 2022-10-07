public class recursion_permutation {
    public static void permutations(String str, String permutation){
        if(str.length()==0){
            System.out.println(permutation);
            return;
        }
        for(int i=0;i<str.length();i++){
            String newString = str.substring(0, i) + str.substring(i+1);
            permutations(newString, permutation+str.charAt(i));
        }
    } 
    public static void main(String[] args) {
        permutations("abc", "");
    }
}
