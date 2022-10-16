public class InsertionSort 
{
  static void insertionSort(int[] arr, int size)
  {
    for (int i=1; i<size; i++)
    {
      for (int j=0; j<i; j++)
      {
        if (arr[j]>arr[i])
        {
          arr[j] = arr[j] + arr[i];
          arr[i] = arr[j] - arr[i];
          arr[j] = arr[j] - arr[i];
        }
      }
    }
      
  }

  static void printArray(int[] arr, int size) 
  {
    for (int i=0; i<size; i++) 
      System.out.print(arr[i] + " ");
    System.out.println();
  }

  public static void main(String[] args) 
  {
    int[] arr = { 10, 7, 8, 9, 1, 5 };
    int n = arr.length;

    insertionSort(arr, n);
    System.out.print("Sorted array: ");
    printArray(arr, n);
  }
}
