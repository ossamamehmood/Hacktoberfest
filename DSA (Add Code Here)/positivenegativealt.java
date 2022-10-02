package array;

public class positivenegativealt {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
		posnegalt(arr);

	}

	// if order matters
	public static void posnegalt(int[] arr) {
		int i = 0;
		while (i < arr.length) {
			if (i % 2 == 0 && arr[i] >= 0 || i % 2 != 0 && arr[i] < 0) {
				int wrongindex = i;
				if (i % 2 == 0) {
					while (i < arr.length && arr[i] >= 0) {
						i++;
					}
				} else {
					while (i < arr.length && arr[i] < 0) {
						i++;
					}
				}
				int lastindex = i;
				if (lastindex == arr.length) {
					break;
				}
				rotatearr(arr, wrongindex, lastindex);
				i = wrongindex + 1;
			} else {
				i++;
			}

		}

		for (

				int j = 0; j < arr.length; j++) {
			System.out.println(arr[j]);
		}

	}

	private static void rotatearr(int[] arr, int wrongindex, int lastindex) {
		// TODO Auto-generated method stub
		int temp = arr[lastindex];
		for (int i = lastindex - 1; i >= wrongindex; i--) {
			arr[i + 1] = arr[i];
		}
		arr[wrongindex] = temp;

	}

}
