import java.util.*; 
public class Main
{
    private static int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // Using min heap concept
        for(int[] mat : matrix)
        {
            for(int num : mat)
            {
                pq.add(num); //Inserting all the element present in matrix into min heap
            }
        }
        while(k > 1)
        {
            pq.poll(); 
            k--;
        }
        return pq.peek();
    }
	public static void main(String[] args) {
        int[][] matrix1 = {{1,5,9},{10,11,13},{12,13,15}};
        int k = 8;
        System.out.println("Test case-1:");
        System.out.println(kthSmallest(matrix1,k));
        int[][] matrix2 = {{1,2},{1,3}};
        k = 2;
        System.out.println("Test case-2:");
        System.out.println(kthSmallest(matrix2,k));
        int[][] matrix3 = {{-5}};
        k = 1;
        System.out.println("Test case-3:");
        System.out.println(kthSmallest(matrix3,k));
	}
}
