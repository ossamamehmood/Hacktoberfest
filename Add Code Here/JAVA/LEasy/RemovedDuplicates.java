package LEasy;

 class Remove_Duplicates {
    public static int removeduplicate(int arr[],int n){
        int i=0;
        for(int j=1;j<n;j++){
            if(arr[i]!=arr[j]){
                arr[i+1]=arr[j];
                i++;
            }
        }
        return i+1;
    }
    public static void main(String[] args) {
        int arr[]={1,1};
        int n=arr.length;
        int removeDuplicates=removeduplicate(arr,n);
        System.out.println(removeDuplicates); //it will return the number of distinct elements in the array.
    }
}
