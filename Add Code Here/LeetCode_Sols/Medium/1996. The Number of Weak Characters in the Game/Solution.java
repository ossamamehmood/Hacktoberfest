class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        int n = properties.length;
        int count = 0;
        int maxN = Integer.MIN_VALUE;
        Arrays.sort(properties, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        for(int i = 0; i < n; i++){
            if(properties[i][1] < maxN)
                count++;
            maxN = Math.max(maxN, properties[i][1]);
        }
        return count;
    }
}
