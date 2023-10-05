# Problem #11 ([Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | Array, Greedy, Two Pointers)

You are given an integer array height of length `n`. There are `n` vertical lines drawn such that the two endpoints of the **i<sup>th</sup>** line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

*Return the maximum amount of water a container can store.*

**Notice** that you may not slant the container.

## Example 1
![image](https://user-images.githubusercontent.com/89616705/187815178-fc833b50-3d87-4e95-a17c-155d0d81a3a8.png)

**Input:**

    height = [1,8,6,2,5,4,8,3,7]
<br/>

**Output:**

    49
<br/>

**Explanation:**
```
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
In this case, the max area of water (blue section) the container can contain is 49.
```

## Example 2
**Input:**

    height = [1,1]
<br/>

**Output:**

    1

## Constraints
- `n == height.length`
- `2 <= n <= 105`
- `0 <= height[i] <= 104`

# Solutions

## Two Pointers(Proof by Formula)

We have an array of integers that represents heights. We have to pick two heights in which when filled water denotes the value of *Area(`A`)*, where *A* represents the area the water takes up.

The idea is get two heights that can contain the largest amount of water.

    A = width * height
<br/>

`width` here represents the distance between the two heights(*e.g. indices `(1, 5)` has a `width` of `4` since `5 - 1 = 4`*). `height` represents the minimum between two heights.

The main idea is the have *two pointers* that represents the indices of two heights(*left and right heights*), by default `leftIndex = 0` and `rightIndex = height.length - 1`. And a *variable* `maxArea` that stores the largest area where water can be contained.
```cpp
int maxArea = 0;
int leftIndex = 0, rightIndex = height.length - 1;
```
<br/>

Next is to loop through the array of `height` while (`leftIndex` < `rightIndex`) holds true.
```cpp
while(leftIndex < rightIndex){
    //  ...statements
}
```
<br/>

**The *while* loop is structured as such:**
```cpp
maxArea = max(maxArea, min(height[leftIndex], height[rightIndex]) * (rightIndex - leftIndex));
```
- First is to assign the value of `maxArea` to which has the larger area, is it the current `maxArea` or the current Area of heights at indices `(leftIndex, rightIndex)`.

```cpp
if(height[leftIndex] < height[rightIndex])
    leftIndex++;
else
    rightIndex;
```
- Move the pointers, if the *left height is less than the right height* then we should move the left height to the its succeeding height, while, if greater than, move the right height to the preceded height.

Once, the **while** loop ends, `maxArea` should already be determined and can already be returned.
```cpp
return maxArea
```

### Code

- **JAVA**
```java
class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int leftIdx = 0, rightIdx = height.length-1;
        
        while(leftIdx < rightIdx){
            maxArea = Math.max(maxArea, Math.min(height[leftIdx], height[rightIdx]) * (rightIdx - leftIdx));
            if(height[leftIdx] < height[rightIdx])
                leftIdx++;
            else
                rightIdx--;
        }
        
        return maxArea;
    }
}
```
<br/>

- **C**++
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int leftIdx = 0, rightIdx = height.size() - 1;
        
        while(leftIdx < rightIdx){
            maxArea = max(maxArea, min(height[leftIdx], height[rightIdx]) * (rightIdx - leftIdx));
            if(height[leftIdx] < height[rightIdx])
                leftIdx++;
            else
                rightIdx--;
        }
        
        return maxArea;
    }
};
```

### Complexity
- **Time:** `O(n)`
- **Space:** `O(1)`
