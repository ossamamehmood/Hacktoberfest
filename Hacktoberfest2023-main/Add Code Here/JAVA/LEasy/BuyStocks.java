package LEasy;

public class BuyStocks {
    public static void main(String[] args) {

        int[] prices={7,1,5,3,6,4};

        int n=prices.length;


        int buyprice=Integer.MAX_VALUE;
        int maxprofiy=0;

        for (int i = 0; i < prices.length; i++) {


            if(buyprice<prices[i]){
                int profit=prices[i]-buyprice;
                if(maxprofiy>profit){

                }
            }

        }







    }
}
