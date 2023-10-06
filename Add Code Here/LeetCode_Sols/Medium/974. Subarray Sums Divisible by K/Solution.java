class Solution {
    public int subarraysDivByK(int[] arr, int k) {
        int n = arr.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        int sum = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            if(sum%k==0)
                count++;
            int rem = sum%k;
            if(rem<0)
                rem = rem+k;
            if(map.containsKey(rem))
                count+=map.get(rem);
            map.put(rem,map.getOrDefault(rem,0)+1);
        }
        return count;
    }
}
