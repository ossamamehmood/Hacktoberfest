public class MajorityElement {
    public static void main(String[] args) {
        int[] nums = new int[]{3,2,3};
        int[] count = new int[nums.length];
        int curr;
        for(int i = 0;i<nums.length - 1;i++){
            curr = nums[i];
            for(int j = i;j<nums.length;j++){
                if(curr == nums[j]){
                    count[i]++;
                }
            }
        }
        int max =0;
        int index = 0;
        for(int i = 0;i<count.length;i++){
            if(count[i] > max){
                max = count[i];
                index = i;
            }
        }
        System.out.println(nums[index]);
    }
}
