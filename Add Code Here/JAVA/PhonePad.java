public class PhonePad {
    public static void main(String[] args) {
        String num = "123";
        pad("", num);
        System.out.println(padCount("", num));
    }

    // display letter combinations
    static void pad(String p, String up) {
        if (up.isEmpty()) {
            System.out.println(p);
            return;
        }

        int digit = up.charAt(0) - '0';
        for (int i = (digit - 1) * 3; i < digit * 3; i++) {
            char ch = (char) ('a' + i);
            pad(p + ch, up.substring(1));
        }
    }

    // return count of letter combinations
    static int padCount(String p, String up) {
        if (up.isEmpty()) {
            return 1;
        }

        int count = 0;
        int digit = up.charAt(0) - '0';
        for (int i = (digit - 1) * 3; i < digit * 3; i++) {
            char ch = (char) ('a' + i);
            count += padCount(p + ch, up.substring(1));
        }
        return count;
    }
}
