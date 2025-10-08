#!/usr/bin/env python3
"""
Binary Search Algorithm Implementation
Author: Shekhar
Description: Efficient search algorithm for sorted arrays
Time Complexity: O(log n)
Space Complexity: O(1)
"""

def binary_search(arr, target):
    """
    Perform binary search on a sorted array.
    
    Args:
        arr: Sorted list of integers
        target: Value to search for
        
    Returns:
        Index of target if found, -1 otherwise
    """
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

def binary_search_recursive(arr, target, left=0, right=None):
    """
    Recursive implementation of binary search.
    
    Args:
        arr: Sorted list of integers
        target: Value to search for
        left: Left boundary (default: 0)
        right: Right boundary (default: len(arr) - 1)
        
    Returns:
        Index of target if found, -1 otherwise
    """
    if right is None:
        right = len(arr) - 1
    
    if left > right:
        return -1
    
    mid = left + (right - left) // 2
    
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, right)
    else:
        return binary_search_recursive(arr, target, left, mid - 1)

def main():
    """Test the binary search implementations."""
    # Test cases
    test_arrays = [
        [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
        [2, 4, 6, 8, 10, 12, 14, 16],
        [1, 3, 5, 7, 9, 11, 13, 15, 17],
        [5],
        []
    ]
    
    test_targets = [5, 8, 1, 20, 0]
    
    print("Binary Search Algorithm Test")
    print("=" * 40)
    
    for i, arr in enumerate(test_arrays):
        if i < len(test_targets):
            target = test_targets[i]
            print(f"\nArray: {arr}")
            print(f"Target: {target}")
            
            # Iterative search
            result_iter = binary_search(arr, target)
            print(f"Iterative result: {result_iter}")
            
            # Recursive search
            result_rec = binary_search_recursive(arr, target)
            print(f"Recursive result: {result_rec}")
            
            if result_iter != -1:
                print(f"✅ Found at index {result_iter}")
            else:
                print("❌ Target not found")

if __name__ == "__main__":
    main()
