public class recursion_waysToinvitePeopleInParty {
    public static int TotalWays(int n){
        if(n<=1){
            return 1;
        }
        //single
        int single_ways = TotalWays(n-1);

        //in pair
        int pair_ways = (n-1)*TotalWays(n-2);

        return single_ways+pair_ways;
    }
    public static void main(String[] args) {
        
        System.out.println("total no. of ways are "+TotalWays(4));
    }
}
