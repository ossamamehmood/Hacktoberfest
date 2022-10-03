class Solution {
  public boolean backspaceCompare(String s, String t) {
    return formBackSpaceString(s).equals(formBackSpaceString(t));
  }
  
  private String formBackSpaceString(String s) {
    Stack<Character> stack = new Stack<>();
    for (char c : s.toCharArray()) {
      if (c == '#') {
        if (!stack.isEmpty()) {
          stack.pop();
        }
      } else {
        stack.push(c);
      }
    }
    StringBuilder sb = new StringBuilder();
    while (!stack.isEmpty()) {
      sb.append(stack.pop());
    }
    return sb.toString();
  }
}
