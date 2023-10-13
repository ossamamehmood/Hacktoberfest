package Java.Leetcode;

//   Q : 8. String to Integer (atoi)

public class StringToInteger {


    //          error           //
    public static void main(String[] args) {
        String s = "4193 with words";
//        if (s.length() == 0) {
//            System.out.println(-1);
//        }else {
//        s = s.replaceAll("\\s", "");
            System.out.println(myAtoi(s));
//        }
    }

    public static int myAtoi(String s) {
                s = s.replaceAll("\\s", "");

        String str = skip(s);
        return Integer.parseInt(str);
    }

    static String skip(String up) {
        if (up.isEmpty()) {
            return "";
        }

        char ch = up.charAt(0);
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            return ch + skip(up.substring(1));
        } else {
            return skip(up.substring(1));
        }
    }
    // Character.getNumericValue(ch) <= 9 && Character.getNumericValue(ch) >= 0 && ch == '-'
}
