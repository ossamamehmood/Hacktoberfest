package backtracking;

public class longestpossibleroute {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int mat[][] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
				{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
		solve(mat, 0, 0, 0, 1, 7);
		System.out.println(max);

	}

	public static int max = Integer.MIN_VALUE;

	public static void solve(int[][] arr, int ans, int i, int j, int di, int dj) {
		if (j == dj && i == di) {
			if (max < ans) {
				max = ans;
			}
			return;
		}

		if (i < 0 || j < 0 || i >= arr.length || j >= arr[0].length || arr[i][j] == 0 || arr[i][j] == -1) {
			return;
		}

		int[] rx = { 1, -1, 0, 0 };
		int[] ry = { 0, 0, 1, -1 };
		arr[i][j] = -1;
		for (int k = 0; k < ry.length; k++) {
			solve(arr, ans + 1, i + rx[k], j + ry[k], di, dj);
		}
		arr[i][j] = 1;
	}

}
