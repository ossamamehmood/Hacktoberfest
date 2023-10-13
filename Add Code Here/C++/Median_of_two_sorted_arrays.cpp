#include <bits/stdc++.h> 
using namespace std; 


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nums;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n)
        {
            nums.push_back(nums1[i]);
            i++;
        }
        while (j < m)
        {
            nums.push_back(nums2[j]);
            j++;
        }
        n = n + m;
        double ans = 0;
        if (n % 2 != 0)
        {
            ans = (double)nums[n / 2];
        }
        else
        {
            ans = (double)(nums[n / 2 - 1] + nums[n / 2]) / 2;
        }
        return ans;
    }


// Driver code 
int main() 
{ 
	vector<int> v1{1,2,3,4,5};
    vector<int> v2{6,7,8,9};
    cout<<"Median is "<< findMedianSortedArrays(v1,v2);

	return 0; 
}

