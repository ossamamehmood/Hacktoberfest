public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        static final int LONGEST_WORD_LEN = 16;

        public int longestStrChain(String[] words) {
            // Calculate number of strings of each length;
            int longestCount = 0;
            int[] lenCounts = new int[LONGEST_WORD_LEN + 1];
            for (int i = words.length - 1; i >= 0; i--)
                longestCount = Math.max(longestCount, ++lenCounts[words[i].length()]);

            // Build an array that for each string length, has an array of indexes to words
            // of that
            // length. Copy the words from the words[] array into the wcs[][] array. The
            // array wcs
            // is indexed by: wcs[string len][index of words of same len]. The wcs[len][0]
            // value is
            // the number of words of that same length that are stored in wcs[len].
            int maxWordLen = 0;
            for (maxWordLen = LONGEST_WORD_LEN; maxWordLen >= 0 && lenCounts[maxWordLen] == 0; maxWordLen--) {
            }
            short[][] wcs = new short[maxWordLen + 1][longestCount + 1];
            for (int i = words.length - 1; i >= 0; i--) {
                int len = words[i].length();
                wcs[len][++wcs[len][0]] = (short) i;
            }

            // Create an uninitialized memorization value for each word now stored as char[]
            // arrays in wcs[][][].
            byte[][] memo = new byte[maxWordLen + 1][longestCount + 1];

            // Start with the longest words and search backward (longest word to shortest
            // word) to find the
            // longest string chain. Stop searching if the longest string chain found if
            // longer or same
            // length as the current word (words are processed longest to shortest), because
            // a longer chain
            // is not possible.
            int longestFound = 1;
            for (int len = maxWordLen; len > 1 && len > longestFound; len--)
                for (int wordIdx = wcs[len][0]; wordIdx >= 1 && len > longestFound; wordIdx--)
                    longestFound = Math.max(longestFound, findPath(len, wordIdx, wcs, memo, words));
            return longestFound;
        }

        // Recursively try to find a path from a word (specified by its length and its
        // index into words of
        // the same length) backward through predecessors, by comparing the word to all
        // words that are one
        // character shorter. Find the longest path from this word backward through
        // shorter words. Memorize
        // the longest path from a word, so we don't have to recalculate it if we try to
        // find the path from
        // this word again.
        private int findPath(int len, int wordIdx, short[][] wcs, byte[][] memo, String[] words) {
            if (len == 1)
                return 1;
            if (memo[len][wordIdx] > 0)
                return memo[len][wordIdx];
            String curWord = words[wcs[len][wordIdx]];
            int longest = 0;
            for (int predIdx = wcs[len - 1][0]; predIdx >= 1 && longest + 1 < len; predIdx--)
                if (isPredecessor(curWord, words[wcs[len - 1][predIdx]]))
                    longest = Math.max(longest, findPath(len - 1, predIdx, wcs, memo, words));
            memo[len][wordIdx] = (byte) (longest + 1);
            return longest + 1;
        }

        // Given two words as Strings, test the second word to see if it is a
        // predecessor of the first word.
        // It is a predecessor if the second word differs from the first word by having
        // exactly one character
        // in the first word that does not match the characters in the second word. The
        // first word will be one
        // character longer than the second word. The second word is a predecessor if
        // deleting one character
        // from the first word can form the second word.
        private boolean isPredecessor(String curWord, String predWord) {
            int diffCount = -1;
            int predIdx = predWord.length() - 1;
            for (int curIdx = curWord.length() - 1; curIdx >= 1; curIdx--) {
                if (curWord.charAt(curIdx) != predWord.charAt(predIdx--)) {
                    if (diffCount++ == 0)
                        return false;
                    predIdx++;
                }
            }
            return (predIdx == -1) || (curWord.charAt(0) == predWord.charAt(0));
        }
    }
}
