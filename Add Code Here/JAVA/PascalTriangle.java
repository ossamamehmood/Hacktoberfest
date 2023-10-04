import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>();
        row.add(1);

        for (int i = 1; i <= rowIndex; i++) {
            long val = (long) row.get(i - 1) * (rowIndex - i + 1) / i;
            row.add((int) val);
        }

        return row;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        List<Integer> result = solution.getRow(4);
        System.out.println(result);
    }
}
