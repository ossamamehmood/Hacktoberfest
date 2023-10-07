import java.util.Scanner;

public class step2gen {
    public static void main(String[] args) {
        int size, i, j;
        int tmp = 0;
        System.out.println("Enter array size :-");
        Scanner sc = new Scanner(System.in);
        size = sc.nextInt();
        int arr[] = new int[10];
        System.out.println("Enter Array elements :- ");
      
         for ( i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }

// System.out.println("Array elemnts Prime sum :- ");
        for( i = 0; i < size; i++){
            for( j = i + 1; j < size; j++){
            boolean isPrime = true;
                    if(arr[i] == arr[j]){
                        for(int k = 2;k<arr[i]/2;k++){
                            if(arr[i]%k==0){
                                isPrime = false;
                                break;
                            }
                        }

                        if(isPrime){
                            // System.out.println(arr[i]);
                            tmp = tmp + arr[i];
                        }
                         
                    }
                    
            }
    }
        System.out.println("Sum of duplicate prime number is :- " +tmp);
}
}