package LEasy;

public class MaxConsecutiveOnes {
    public static void main(String[] args) {

        int[] arr={1,1,0,1,1,1,0,1,1};
        int maxcounter=0;
        int currcounter=0;
        for (int i = 0; i < arr.length; i++) {

            if(arr[i]==1){
                currcounter++;
            }else{
                currcounter=0;
            }
            if(currcounter>maxcounter){
                maxcounter=currcounter;
            }
        }
        System.out.println(maxcounter);

    }
}
