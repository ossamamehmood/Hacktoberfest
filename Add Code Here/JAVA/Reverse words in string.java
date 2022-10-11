public class Main
{
    private static String reverseWords(String s) {
        int j = s.length()-1;
        StringBuilder ans = new StringBuilder();
        while(j>=0){
            StringBuilder word = new StringBuilder();
            char ch = s.charAt(j);
            if(ch != ' '){
                //making the word till we find space
                while(j>=0 && s.charAt(j) != ' '){
                    ch = s.charAt(j);
                    word.insert(0,ch);
                    j--;
                }
                //adding the word to our final sentence
                ans.append(" " + word.toString());
            }else{
                j--;
            }            
        }
        ans.deleteCharAt(0); // removing the space from the start of our reversed sentence since while making a sentence we are adding one additional space in front so we have to remove this space
        return ans.toString();
    }
	public static void main(String[] args) {
		String s1 = "the sky is blue";
		System.out.print("Test case-1 : ");
		System.out.println(reverseWords(s1));

		String s2 = "  hello world  ";
		System.out.print("Test case-2 : ");
		System.out.println(reverseWords(s2));

		String s3 = "a good   example";
		System.out.print("Test case-3 : ");
		System.out.println(reverseWords(s3));
	}
}
