/* Problem Statement
You are given an array ‘pages’ of integer numbers. In this array, the ‘pages[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books to the students. 

Allocate books in a way such that:

Each student gets at least one book.
Each book should be allocated to a student.
Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.*/

solution:--

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int pages[], int n, int m, int numPages) {
    int cntStudents = 1;
    int curSum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > numPages) {
            return false;
        }
        if (curSum + pages[i] > numPages) {
        
            cntStudents += 1;
            
            
            curSum = pages[i];
            
           
            if (cntStudents > m) {
                return false;
            }
        } else {
        
            
            curSum += pages[i];
        }
    }
    return true;
}

int allocateBooks(int pages[], int n, int m) {

  
    if (n < m) {
        return -1;
    }
    
   
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pages[i];
    }
    
   
    int start = 0, end = sum;
    int result = INT_MAX;
    
   
    while (start <= end) {
    
        
        int mid = start + (end - start) / 2;
        if (isPossible(pages, n, m, mid)) {
            result = min(result, mid); 
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}
int main() {
    int n = 4;
    int m = 2;
    int pages[] = {10, 20, 30, 40};
    cout << "The minimum value of the maximum number of pages in book allocation is: " << allocateBooks(pages, n, m) << endl;
}

Time Complexity:-
The time complexity for the above algorithm is O(N*log(Sum)). Here ‘N’ is the number of integers in the array ‘pages,’ and ‘Sum’ is the sum of all the elements of ‘pages.’ For every number ‘mid,’ we have an iteration loop of size ‘N,’ and binary search takes ‘log(Sum)’ time. So, that makes the time complexity O(N*log(Sum)).

Space Complexity:-
The space complexity for the above algorithm is O(1), as we use constant space.

