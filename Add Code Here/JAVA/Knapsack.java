import java.util.Arrays;
import java.util.Comparator;

public class Knapsack {
	

		private static double getMaxValue(int[] wt, int[] val,
										int capacity)
		{
			ItemValue[] iVal = new ItemValue[wt.length];

			for (int i = 0; i < wt.length; i++) {
				iVal[i] = new ItemValue(wt[i], val[i], i);
			}

	
			Arrays.sort(iVal, new Comparator<ItemValue>() {
				@Override
				public int compare(ItemValue o1, ItemValue o2)
				{
					return o2.cost.compareTo(o1.cost);
				}
			});

			double totalValue = 0d;

			for (ItemValue i : iVal) {

				int curWt = (int)i.wt;
				int curVal = (int)i.val;

				if (capacity - curWt >= 0) {
					
					capacity = capacity - curWt;
					totalValue += curVal;
				}
				else {
					
					double fraction
						= ((double)capacity / (double)curWt);
					totalValue += (curVal * fraction);
					capacity
						= (int)(capacity - (curWt * fraction));
					break;
				}
			}

			return totalValue;
		}

		// item value class
		static class ItemValue {
			Double cost;
			double wt, val, ind;

			
			@SuppressWarnings("deprecation")
			public ItemValue(int wt, int val, int ind)
			{
				this.wt = wt;
				this.val = val;
				this.ind = ind;
				cost = new Double((double)val / (double)wt);
			}
		}

		public static void main(String[] args)
		{
			int[] wt = { 5, 10, 20, 30, 40 };
			int[] val = { 30, 20, 100, 90, 160 };
			int capacity = 60;

			double maxValue = getMaxValue(wt, val, capacity);

			
			System.out.println("Maximum value we can obtain = "
							+ maxValue);
		}
	}


