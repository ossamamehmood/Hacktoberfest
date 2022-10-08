public class Solution {

    public static void sumOfTwoArrays(int arr1[], int arr2[], int output[]) {
    	//Your code goes here
        
        int carry = 0,k,i,j;
        
			if(arr1.length > arr2.length) 
            {
				 i = arr1.length - 1;
	             j = arr2.length - 1;
				 while(i >= 0 && j >= 0) 
                 {
						output[i + 1] = (arr1[i] + arr2[j] + carry) % 10;
						carry = (arr1[i] + arr2[j] + carry)/10;
						i--;
						j--;
				}
                
				 for(k = i+1;k > 0 && i >= 0;k--) 
                 {
					 output[k] = (arr1[i] + carry) % 10;
				     carry = (arr1[i] + carry) / 10;
	               i--;
				 } 
				 output[0] = carry;
			}
			else 
            {
				 i = arr1.length - 1;
	             j = arr2.length - 1;
                
				 while(i >= 0 && j >= 0) 
                 {
						output[j + 1] = (arr1[i] + arr2[j] + carry) % 10;
						carry = (arr1[i] + arr2[j] + carry)/10;
						i--;
						j--;
				}
                
				 for(k = j+1;k > 0 && j >= 0;k--) 
                 {
					 output[k] = (arr2[j] + carry) % 10;
				     carry = (arr2[j] + carry) / 10;
	                 j--;
				 }
                
				 output[0] = carry;
		}
    
        
    }

}