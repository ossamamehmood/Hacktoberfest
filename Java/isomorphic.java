import java.io.*;
import java.util.*;
class isomorphic {
    // Function to check if two strings are isomorphic.
    // gfg verified code
    public static boolean areIsomorphic(String str1, String str2) {
        if (str1.length() != str2.length())
            return false;
        boolean visited[] = new boolean[256];
        int map[] = new int[256];
        Arrays.fill(map, -1);
        for (int i = 0; i < str1.length(); i++) {
            if (map[str1.charAt(i)] == -1) {
                if (visited[str2.charAt(i)] != false)// opposite has come before with different mapping
                    return false;
                visited[str2.charAt(i)] = true;
                map[str1.charAt(i)] = str2.charAt(i);
            } else {
                if (map[str1.charAt(i)] != str2.charAt(i))
                    return false;
            }
        }
        return true;
        // Your code here
    }
}
