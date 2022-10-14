import java.io.*;
class BinarySearch {
	
	static int binary_Search(int arr[], int l, int r, int x)
	{
		if (r >= l) {
			int mid = l + (r - l) / 2;

			
			if (arr[mid] == x)
				return mid;

			
			if (arr[mid] > x)
				return binary_Search(arr, l, mid - 1, x);

			
			return binary_Search(arr, mid + 1, r, x);
		}

		
		return -1;
	}
	

	
	public static void main(String args[])
	{
		BufferedReader ob=new BufferedReader(new InputStreamReader (System.in));
        try{
		int arr[] = { 2, 3, 4, 10, 40 };
        int x;
		int n = arr.length;
        System.out.println("enter the number");
		 x = Integer.parseInt(ob.readLine());
		int result = binary_Search(arr, 0, n - 1, x);
		if (result == -1)
			System.out.println("Element not present");
		else
			System.out.println("Element found at index "
							+ result);
		}
		catch(IOException o1){
            System.out.println(o1);
		}
	}
}


