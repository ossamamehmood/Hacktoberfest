class Main
{
  static int max_ref; //stores the longest Incresing Subsequence
  static int _lis(int arr[], int n)
  {
    if(n==1)  //base case
      return 1;
    int res,max_ending_here=1; //'max_ending_here' is length of LIS ending with
                               //arr[n-1]
    for(int i=1;i<n;i++){  //Recursively get all LIS ending with arr[0],...arr[n-2]
      res=_lis(arr,i);
      if(arr[i-1]<arr[n-1] && res+1>max_ending_here)
        max_ending_here=res+1;
    }
    if(max_Ref < max_ending_here)  //Compare max value and update
      max_ref = max_ending_here;

    return max_ending_here;
  }

  static int lis(int arr[],int n)
  {
    max_ref=1;
    _lis(arr,n);
    return max_ref;

  }

  public static void main(String args[])
  {
    int arr[] = {10,22,9,33,21,50,41,60};
    int n=arr.length;
    System.out.println("Length of lis is "+lis(arr,n) +"/n");
  }
}
