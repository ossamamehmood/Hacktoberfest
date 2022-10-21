public class recursion_allPossiblePathInAMatrix {
    public static int possiblePath(int n,int m,int fx, int fy){
        if(n==fx-1 && m==fy-1){
            return 0;
        }
        else if(n==fx-1 || m==fy-1){
            return 1;
        }
        //downward
        int downward = possiblePath(n+1, m, fx, fy);

        //rightward
        int rightward = possiblePath(n, m+1, fx, fy);

        return downward+rightward;
    }
    public static void main(String[] args) {
        System.out.println("total no. of ways are "+possiblePath(0, 0, 1, 4));
    }
    
}
