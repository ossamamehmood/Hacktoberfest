//package Stacklevel1;

import java.util.Stack;

public class Balanced_Brackets {
    public static boolean solution(String s){
        Stack <Character> st=new Stack<>();
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(ch==')'){
                if(st.size()==0){
                    return false;
                }
                while(st.peek()!='('){
                    st.pop();
                }
                st.pop();
            }
            else if(ch=='}'){
                if(st.size()==0){
                    return false;
                }
                while(st.peek()!='{'){
                    st.pop();
                }
                st.pop();
            }
            else if(ch==']'){
                if(st.size()==0){
                    return false;
                }
                while(st.peek()!='['){
                    st.pop();
                }
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        String s1="[(a+b)+{(c+d)+(e/f)}]";
        String s2="[(a+b)+{(c+d)+(e/f)]}";
        String s3="[(a+b)+{(c+d)+(e/f)}";
        System.out.println(solution(s3));
    }
}
