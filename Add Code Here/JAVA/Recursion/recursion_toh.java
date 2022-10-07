public class recursion_toh {
    static int count = 0;
    public static void towerOfHanoi(int n,String source, String helper, String destination,int arr[]){
        if(n==1){
            System.out.println("Disk no. "+n+" transferred from "+source+" to "+destination);
            // arr[0]++;
            count++;
            return;
        }
        towerOfHanoi(n-1, source, destination, helper,arr);
        System.out.println("Disk no. "+n+" transferred from "+source+" to "+destination);
        // arr[0]++;
        count++;
        towerOfHanoi(n-1, helper, source, destination,arr);
    }
    public static void main(String[] args) {
        int arr[] = new int[1];
        arr[0]= 0;
        towerOfHanoi(3, "S", "H", "D", arr);
        // System.out.println("total no. of steps involved are "+arr[0]);
        System.out.println("total no. of steps involved are "+count);
    }
}
