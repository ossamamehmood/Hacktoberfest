//Queue Important Question
//Hard C++ Solution 
//USING STL dequue and Vector

//Leetcode 239. no question
class Solution{
public:
  
  vector<int>maxSlidingWindow(vector<int>&nums, int k){
    dequeue<int>dq;
    vector<int>ans; 
  //first window of k size
  for(int i=0;i<k;i++){
    //chote element remove kardo
  while(!dq.empty() && nums[i] >= nums[dq.back()]){
    dq.pop_back();
  }
  //inserting index, so that we can checkout of window element
  dq.push_back(i);
  }
  //store ans for first window
  ans.push_back(nums[dq.front()]);// storing the value of array
  
  //Track the remaining windows
  for(int i=k;i<nums.size();i++){
    //out of window element ko remove kardia
  if(!dq.empty() && i-dq.front() >= k){
  dq.pop_front();
  }
  
  //now again for current element , smallest element shouldbe removed
  while(!dq.empty() && nums[i] >= nums[dq.back()]){
    dq.pop_back();
  }
  //inserting index , so that we can checkout of windows element
  dq.push_back(i);
  
  // Store the current window ans
  ans.push_back(nums[dq.front()]);
  
    }
      return ans;
  }
};
