class Solution {
    public String reverseWords(String s) {
        StringBuilder res = new StringBuilder();
        String[] arr = s.split(" ");
        for (String str : arr){
            res.append(new StringBuffer(str).reverse().append(" "));
        }
        
       // res.deleteCharAt(res.length() - 1);   If you don't want to use trim()
        return res.toString().trim();        
    }
}  