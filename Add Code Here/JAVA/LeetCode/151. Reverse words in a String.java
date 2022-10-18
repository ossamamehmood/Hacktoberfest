class Solution {
    public String reverseWords(String s) {
        int i=s.length()-1;
        StringBuilder res= new StringBuilder("");
        while(i>=0){
            while(i>=0 && s.charAt(i)==' ') --i;
            if(i<0) break;
            int j=i;
            
            while(i>=0 && s.charAt(i)!=' ') --i;
            if(res.isEmpty()){
                res=res.append(s.substring(i+1,j+1));
            }
            else{
                res=res.append(" "+s.substring(i+1,j+1));
            }
            
        }
        String ans=res.toString();
        return ans;
    }
}