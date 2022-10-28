import java.util.*;

public class BestTimeToBuyAndSellStockTwo {

    public static void main(String[] args) throws Exception {
        int prices[] = { 1, 3, 4, 2, 6, 1, 6 };
        System.out.println(maxProfit(prices));
    }

    public static int maxProfit(int[] prices) {
        Map<String, Integer> mp = new HashMap<>();
        return solve(prices, 0, true, mp);
    }

    public static int solve(int price[], int i, boolean canBuy, Map<String, Integer> mp) {

        if (i >= price.length)
            return 0;

        String key = i + "!" + canBuy;

        if (mp.containsKey(key))
            return mp.get(key);

        if (canBuy) {

            int idle = solve(price, i + 1, canBuy, mp);
            int buying = (-1 * price[i]) + solve(price, i + 1, false, mp);
            mp.put(key, Math.max(idle, buying));
            return mp.get(key);

        } else {

            int idle = solve(price, i + 1, canBuy, mp);
            int selling = price[i] + solve(price, i + 1, true, mp);
            mp.put(key, Math.max(idle, selling));
            return mp.get(key);

        }
    }
}