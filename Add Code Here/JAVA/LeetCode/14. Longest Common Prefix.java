class Solution {
    public String longestCommonPrefix(String[] strs) {
        String temp=strs[0];
        for(int i=0; i<strs.length; ++i){
            while(strs[i].indexOf(temp)!=0){
                temp=temp.substring(0,temp.length()-1);
                if(temp.isEmpty()) return "";
            }
        }
        return temp;
    }
}
