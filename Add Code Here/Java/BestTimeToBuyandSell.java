public class BestTimeToBuyandSell {
	public static void main(String[] args) {
		int prices[] = new int[]{7, 1, 5, 3, 6, 4};
		System.out.println(maxProfit(prices));
	}

	public static int maxProfit(int[] prices) {
		int left = 0, right = 1;
		int profit;
		int maxP = 0;
		while (right < prices.length) {
			if (prices[right] - prices[left] > 0) {
				profit = prices[right] - prices[left];
				maxP = Math.max(maxP, profit);
			} else {
				left = right;
			}
			right++;
		}
		return maxP;
	}


}