import java.util.*;
public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public List<String> fullJustify(String[] words, int maxWidth) {
            List<String> result = new ArrayList<>();

            for (int i = 0, wordCount, lineLength; i < words.length; i += wordCount) {
                for (wordCount = 0, lineLength = 0; i + wordCount < words.length &&
                        lineLength + words[i + wordCount].length() + wordCount <= maxWidth; wordCount++) {
                    lineLength += words[i + wordCount].length();
                }

                StringBuilder lineBuilder = new StringBuilder(words[i]);

                if (wordCount == 1 || i + wordCount == words.length) {
                    for (int j = 1; j < wordCount; j++) {
                        lineBuilder.append(" ").append(words[i + j]);
                    }
                    lineBuilder.append(" ".repeat(maxWidth - lineBuilder.length()));
                } else {
                    int totalSpaces = (maxWidth - lineLength) / (wordCount - 1);
                    int extraSpaces = (maxWidth - lineLength) % (wordCount - 1);

                    for (int j = 1; j < wordCount; j++) {
                        int spacesToAdd = totalSpaces + (extraSpaces-- > 0 ? 1 : 0);
                        lineBuilder.append(" ".repeat(spacesToAdd)).append(words[i + j]);
                    }
                }
                result.add(lineBuilder.toString());
            }
            return result;
        }
    }
}