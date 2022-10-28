// https://leetcode.com/problems/richest-customer-wealth/ (Leetcode easy)

public class RichGuyWealth {
    
    public static void main(String[] args) {
        int[][] accounts = new int[][]{{2, 1}, {5, 6}, {3, 5}};
        System.out.println(MaxWealth(accounts));
    }

    static int MaxWealth(int[][] accounts) {
        int max = -2147483648;

        for(int person = 0; person < accounts.length; ++person) {
            int rowsum = 0;

            for(int account = 0; account < accounts[person].length; ++account) {
                rowsum += accounts[person][account];
            }

            if (rowsum > max) {
                max = rowsum;
            }
        }

        return max;
    }
}