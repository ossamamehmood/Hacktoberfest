
public class BinarySearch {
    public static int binarySearch(int arr[],int element){
        int low =0;
        int high = arr.length-1;
        while(low<=high){
            int mid = low-(low-high)/2;
            if(arr[mid]==element){
                return mid;
            } else if (arr[mid]>element) {
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
        //Time Complexity
        //O(logn)
    }

    //Using recursion
    public static int binarySearchRecursion(int arr[],int l,int r,int element){
        if(l>r){
            return -1;
        }
        int mid = l-(l-r)/2;
        if(arr[mid]==element){
            return mid;
        } else if (arr[mid]>element) {
            return binarySearchRecursion(arr,l,mid-1,element);
        }else{
            return binarySearchRecursion(arr,mid+1,r,element);
        }

        //Time Complexity
        //O(logn)
    }
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5};
        System.out.println(binarySearch(arr,2));
        System.out.println(binarySearchRecursion(arr,0,arr.length-1,2));
    }
}
