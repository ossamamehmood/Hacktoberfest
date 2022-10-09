import java.util.ArrayList;

public class recursion_subsequence {
    static void subseq(String p, String up) {
        if (up.isEmpty()) { 
            System.out.println(p);
            return;
        }

        char ch = up.charAt(0);

        subseq(p + ch, up.substring(1));
        subseq(p, up.substring(1));

    }

    static ArrayList<String> subseqRet(String p, String up) {
        if (up.isEmpty()) { 
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        char ch = up.charAt(0);

        ArrayList<String> left = subseqRet(p + ch, up.substring(1));
        ArrayList<String> right = subseqRet(p, up.substring(1));

        left.addAll(right);
        return left;

    }

    static void subseqAscii(String p, String up) {
        if (up.isEmpty()) { 
            System.out.println(p);
            return;
        }

        char ch = up.charAt(0);

        subseqAscii(p + ch, up.substring(1));
        subseqAscii(p, up.substring(1));
        subseqAscii(p + (ch + 0), up.substring(1));

    }
    public static void main(String[] args) {
       subseq("", "abc");
       System.out.println(subseqRet("", "abc"));
       subseqAscii("", "abc");
        
    } 
}
