//leetcode - Text Justification

import java.util.ArrayList;
import java.util.List;

public class Text_Justification {
    public static void main(String[] args) {
        String [] words = {"This", "is", "an", "example", "of", "text", "justification."};
        int maxWidth = 16;
        System.out.println(fullJustify(words,maxWidth));
    }
    public static List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int i = 0;
        int n = words.length;
        
        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            while (j < n && (lineLength + words[j].length() + (j - i) <= maxWidth)) {
                lineLength += words[j].length();
                j++;
            }
            
            int diff = maxWidth - lineLength;
            int numberOfWords = j - i;
            
            if (numberOfWords == 1 || j >= n) {
                result.add(leftJustify(words, diff, i, j));
            } else {
                result.add(middleJustify(words, diff, i, j));
            }
            
            i = j;
        }
        
        return result;
    }

    private static String leftJustify(String[] words, int diff, int i, int j) {
        int spaceOnRight = diff - (j - i - 1);
        
        StringBuilder result = new StringBuilder(words[i]);
        
        for (int k = i + 1; k < j; ++k) {
            result.append(" ").append(words[k]);
        }
        
        result.append(" ".repeat(spaceOnRight));
        return result.toString();
    }
    private static String middleJustify(String[] words, int diff, int i, int j) {
        int spacesNeeded = j - i - 1;
        int totalSpaces = diff / spacesNeeded;
        int extraSpaces = diff % spacesNeeded;

        StringBuilder result = new StringBuilder(words[i]);
        
        for (int k = i + 1; k < j; ++k) {
            int spacesToApply = totalSpaces + (extraSpaces-- > 0 ? 1 : 0);
            result.append(" ".repeat(spacesToApply)).append(words[k]);
        }
        
        return result.toString();
    }
}
