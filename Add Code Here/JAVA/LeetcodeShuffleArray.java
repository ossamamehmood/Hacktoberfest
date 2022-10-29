
public class ShuffleString {
    public static void main(String[] args) {
        String s = "codeleet";
        int[] indices = {4,5,6,7,0,2,1,3};

        char[] str = s.toCharArray();
        char[] ans = new char[indices.length];

        for (int i = 0; i < indices.length; i++) {
            ans[indices[i]] = str[i];

        }

        System.out.println(str);
        System.out.println(ans);
        System.out.println(String.valueOf(ans));
    }
}
