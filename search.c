int search(int* arr, int n, int target) {
int low;

int high;

int res=-1;

low=0;

high=n-1;

while(low<=high){

int mid=(low+high)/2;

if(arr[mid]>target){

high=mid-1;

}

else if(arr[mid]<target){

low=mid+1;

}

else{

res=mid;

break;

}

}

return res;
}
