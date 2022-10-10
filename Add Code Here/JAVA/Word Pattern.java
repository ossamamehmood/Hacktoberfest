class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        Map<Character,String> wordMap = new HashMap<>();
        Map<String, Character> charMap = new HashMap<>();
        if(pattern.length()!=words.length){
            return false;
        }
        for(int i= 0;i<pattern.length();i++){
            if(wordMap.containsKey(pattern.charAt(i)) && words[i].equals(wordMap.get(pattern.charAt(i)))){
                continue;
            } else if(!wordMap.containsKey(pattern.charAt(i))){
                if(wordMap.containsValue(words[i])){
                    return false;
                }
                wordMap.put(pattern.charAt(i), words[i]);
            } else if(wordMap.containsKey(pattern.charAt(i)) && !words[i].equals(wordMap.get(pattern.charAt(i)))){
                return false;
            }
        }
        return true;
    }
}
