public class leetcode1295 {
    public static void main(String[] args) {
       int [] nums = {1,12,367,3637};
        System.out.println(findNumbers(nums));
    }
    static  public int findNumbers(int[] nums) {

        int count = 0;
        for (int num : nums){
            if (even(num)){
                count++;
            }
        }
        return  count;
    }

    static public boolean  even(int num){
         int noofdigits = digits(num);

         return noofdigits % 2 == 0;
    }

    static  public  int digits(int num){

        if(num < 0){
            num = num * -1;
        }
        if(num == 0){
            return  1;
        }
        int count = 0;
        while(num > 0){
            count ++;
            num = num / 10;
        }
        return  count;
    }
    //shortcut
    /* public digit(int num){
    return (int)(Math.log10(num)) + 1;
    }
     */
 }
