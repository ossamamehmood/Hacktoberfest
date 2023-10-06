//  Using for loop

class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int n = 0;
        for(String op: operations){
            if (op.charAt(1) == '+') n++;
            else n--;
        }
        return n;
    }
}
