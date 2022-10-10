// A Java Program that shows the segment tree operations like construction, query and   
// update  
public class SegTree  
{  
int stArr[]; // The array that keeps the nodes of the segment tree  
// Constructor to generate the segment tree from the given array.   
// The constructor allocates memory for the segment tree and invokes  
// the method constructST() to fill the memory allocated  
SegTree(int a[], int s)  
{  
// Allocate memory for segment tree  
//Height of segment tree  
int h = (int) (Math.ceil(Math.log(s) / Math.log(2)));  
//Maximum size of segment tree  
int maxSize = 2 * (int) Math.pow(2, h) - 1;  
// for allocatiing the memory for the array   
// that represents the segment tree  
stArr = new int[maxSize]; constructST(a, 0, s - 1, 0);  
}  
// A utility method to find the middle index from the corner indices.  
int getMidIndex(int f, int l)   
{  
return f + (l - f) / 2;  
}  
// A recursive method to find the sum of the values in the given range  
// of the given array. The following are the parameters for the method.  
  
// stArr --> The array representing the segment tree  
// si --> Index of the current node in the segment tree.   
// Initially, 0 is passed as the root is always at the index 0  
// x & y --> Start and end indices of the segment represented  
//              by the current node, i.e., stArr[si]  
// i & j --> Start and end indices of the query range  
int getSumUtil(int x, int y, int i, int j, int si)  
{  
// If the segment of the node is the part of the given range,   
// then return the sum of the segment  
if (i <= x && j >= y)  
{  
return stArr[si];  
}  
// If the segment of the node is outside of the given range  
if (y < i || x > j)  
{  
return 0;  
}  
  
// If a part of the segment overlaps with the range given  
int midVal = getMidIndex(x, y);  
return getSumUtil(x, midVal, i, j, 2 * si + 1) +  
    getSumUtil(midVal + 1, y, i, j, 2 * si + 2);  
}  
// A recursive method to update the nodes that have the given  
// index in their range. The following are the parameters  
//  si, x and y are same as the getSumUtil() method  
//  j --> index of the element to be updated. The index is in  
//        the input array.  
// val --> Value that has to be added to all of the nodes which have j in the range   
void updateValUtil(int x, int y, int j, int val, int si)  
{  
// Base Case: If the input index lies outside the range of  
// this segment  
if (j < x || j > y)  
{  
return;  
}  
// If the range of the node contains the input index, then update the  
// value of the node and its children  
stArr[si] = stArr[si] + val;  
if (y != x)   
{  
int midVal = getMidIndex(x, y);  
updateValUtil(x, midVal, j, val, 2 * si + 1);  
updateValUtil(midVal + 1, y, j, val, 2 * si + 2);  
}  
}  
// The method is to update the value in the input array and the segment tree.  
// It uses the updateValUtil() to update the value in the segment tree  
void updateVal(int a[], int s, int j, int newVal)  
{  
// Check for erroneous input index  
if (j < 0 || j > s - 1)   
{  
System.out.println("Input is Invalid");  
return;  
}  
// Get the difference between the old value and new value  
int diffVal = newVal - a[j];  
// Update the value in array  
stArr[j] = newVal;  
// Update the values of nodes in segment tree  
updateValUtil(0, s - 1, j, diffVal, 0);  
}  
// Returning the sum of elements in the range from the index x (query start) to  
// y (query end). It uses the method getSumUtil()  
int getSum(int s, int x, int y)  
{  
// Checking for the absurd input values  
if (x < 0 || x > s - 1 || x > y)   
{  
System.out.println("The input is invalid");  
return -1;  
}  
return getSumUtil(0, s - 1, x, y, 0);  
}  
// A recursive method that does the construction of the Segment Tree for the array   
// a[x ... y].  
// si is the index of the current node in the segment tree stArr  
int constructST(int a[], int x, int y, int si)  
{  
// If only one element is present in the array, store it   
// in the current node of the segment tree and then return  
if (x == y)   
{  
stArr[si] = a[x];  
return a[x];  
}  
// If there are more than one element, then apply recurrence in the left and  
// right subtrees and the store the sum of values in this node  
int mid = getMidIndex(x, y);  
stArr[si] = constructST(a, x, mid, si * 2 + 1) +  
    constructST(a, mid + 1, y, si * 2 + 2);  
return stArr[si];  
}  
// Main method  
public static void main(String argvs[])  
{  
// input array  
int a[] = {2, 4, 7, 10, 12, 13};  
int size = a.length; // size of the input array  
// Building the segment tree from the input array  
SegTree tree = new SegTree(a, size);  
// Printing the sum of values in the input array from index 1 to 4  
System.out.println("Sum of values in the given range 1 to 4 = " + tree.getSum(size, 1, 4));  
// Update: setting arr[3] = 11 and updating the corresponding segment  
// of the tree nodes  
tree.updateVal(a, size, 3, 11);  
// Finding the sum after the value is getting updated  
System.out.println("Updated sum of values in the given range = " + tree.getSum(size, 1, 4));  
}  
}  
