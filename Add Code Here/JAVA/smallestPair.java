/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;

/* Name of the class has to be "Main" only if the class is public. */
public class smallestPair {
    public static void main(String[] args) throws Exception {
        // your code goes here
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();

            int a[] = new int[n];

            int min1 = Integer.MAX_VALUE;
            int min2 = Integer.MAX_VALUE;

            for (int k = 0; k < n; k++)
            {
                a[k] = sc.nextInt();
            }

            for (int i = 0; i < n; i++) {
                if (a[i] < min1) {
                    min1 = a[i];
                }
                for (int j = 0; j < n; j++)
                {
                    if (a[j] < min2 && a[j] > min1)
                    {
                        min2 = a[j];
                    }
                }
            }
//            System.out.println("min1 = " + min1);
//            System.out.println("min2 = " + min2);

            System.out.println("" + (min1+min2));
        }
    }
}
