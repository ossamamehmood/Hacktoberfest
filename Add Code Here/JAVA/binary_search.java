public class binary_search {
    public static void main(String[]args)
    {
        int [] arr = {-12,34,21,45,56,76,22};
        int target = 34;
        int ans = Binarysearch(arr,target);
        System.out.println(ans);

    }
    static int Binarysearch (int [] arr, int target)
    {
        int start = 0;
        int end = arr.length-1;

        while(start <= end)
        {
            int mid = start + (end-start) / 2;
            if(target <arr[mid])
            {
                end = mid -1;
            }
            else if(target > arr[mid])
            {
                start = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    }
