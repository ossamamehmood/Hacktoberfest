class Solution {
    public int[] numsSameConsecDiff(int n, int k) {
        if(n == 1) return new int[]{k};
        List<Integer> list = new ArrayList<Integer>();
        int min = (int) Math.pow(10, n - 1);
        for(int i = 1; i < 10; i++){
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(i);
            while(!q.isEmpty()){
                int num = q.poll();
                if (num >= min){
                    list.add(num);
                    continue;
                }
                int x = num%10;
                if(k > 0 && x - k >= 0)
                    q.add(num * 10 + x - k);
                if(x + k < 10)
                    q.add(num * 10 + x + k);
            }
        }
        return list.stream()
                   .mapToInt(i -> i)
                   .toArray();
    }
}
