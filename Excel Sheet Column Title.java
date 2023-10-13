public class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder out = new StringBuilder();
        while (columnNumber > 0) {
            out.insert(0, (char) ('A' + (columnNumber - 1) % 26));
            columnNumber = (columnNumber - 1) / 26;
        }
        return out.toString();
    }
}
