
public class FindFirstAndLastIndex {
	public static int findFirst(int[]arr, int target) {
		int s = 0;
		int e = arr.length-1;
		while(s<=e) {
			int mid = s+(e-s)/2;
			if(arr[mid] == target) {
				e = mid-1;
			}else if(arr[mid]>target) {
				e = mid-1;
			}else {
				s = mid+1;
			}
		}
		return s;
	}
	public static int findLast(int[]arr, int target) {
		int s = 0;
		int e = arr.length-1;
		while(s<=e) {
			int mid = s+(e-s)/2;
			if(arr[mid] == target) {
				s = mid+1;
			}else if(arr[mid]>target) {
				e = mid-1;
			}else {
				s = mid+1;
			}
		}
		return e;
	}
	public static void main(String[]args) {
		int target = 2;
		int[] arr = {2, 2, 2, 2, 2, 2, 4, 5, 6};
		int start = findFirst(arr, target);
		int end = findLast(arr, target);
		System.out.println("Starting index = "+start+" Ending Index = "+end);
	}
}
