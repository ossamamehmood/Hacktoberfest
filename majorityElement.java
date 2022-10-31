public class MajorityElement {
    static int majorityElement(int a[]){
        int curElement = -1;
        int count = 0;

        for (int i = 0; i <a.length ; i++) {
            if (count == 0){
                curElement = a[i];
                count = 1;
            }else {
                if (a[i] == curElement){
                    count++;
                }else {
//                    curElement = a[i];
                    count--;
                }
            }

        }
        int finalCount = 0;
        for (int i = 0; i < a.length; i++) {
            int e = a[i];
            if (e == curElement) {
                finalCount++;
            }

        }
        if (finalCount > a.length/2){
            return curElement;
        }else {
            return -1;
        }
    }
    public static void main(String[] args) {
        int a [] = {3,2,3};

        System.out.println(majorityElement(a));
        
    }
}
