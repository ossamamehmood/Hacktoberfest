
class CombSort
{
	int getNextGap(int gap)
	{
		gap = (gap*10)/13;
		if (gap < 1)
			return 1;
		return gap;
	}
	void sort(int arr[])
	{
		int n = arr.length;
		int gap = n;
		boolean swapped = true;
		while (gap != 1 || swapped == true)
		{
			gap = getNextGap(gap);
			swapped = false;
			for (int i=0; i<n-gap; i++)
			{
				if (arr[i] > arr[i+gap])
				{
					// Swap array
					int temp = arr[i];
					arr[i] = arr[i+gap];
					arr[i+gap] = temp;
					swapped = true;
				}
			}
		}
	}
// Main method
	public static void main(String args[])
	{
		CombSort ob = new CombSort();
		int arr[] = {18, 24, 11, 46, -3, -54, 13, -16, 18, 0};
		ob.sort(arr);

		System.out.println("sorted array");
		for (int i=0; i<arr.length; ++i)
			System.out.print(arr[i] + " ");

	}
}

// By Rufus Paul
