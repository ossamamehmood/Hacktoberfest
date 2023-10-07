class Solution {
  String reverseWords(String s) {
      String rev = "";
      List words = s.split(" ");
      for (int i = 0 ; i< words.length; i++){
          rev = rev + words[i].split("").reversed.join() + " ";
          }
          
          return rev.trim();
  }
}