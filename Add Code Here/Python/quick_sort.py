#!/usr/bin/env python3
"""
Quick Sort Algorithm Implementation
Author: Shekhar
Description: Efficient sorting algorithm using divide and conquer
Time Complexity: O(n log n) average case, O(n²) worst case
Space Complexity: O(log n) average case
"""

def quick_sort(arr):
    """
    Sort an array using Quick Sort algorithm.
    
    Args:
        arr: List of integers to sort
        
    Returns:
        Sorted list
    """
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return quick_sort(left) + middle + quick_sort(right)

def quick_sort_inplace(arr, low=0, high=None):
    """
    In-place Quick Sort implementation.
    
    Args:
        arr: List to sort
        low: Starting index
        high: Ending index
        
    Returns:
        None (sorts in place)
    """
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        # Partition the array
        pivot_index = partition(arr, low, high)
        
        # Recursively sort elements before and after partition
        quick_sort_inplace(arr, low, pivot_index - 1)
        quick_sort_inplace(arr, pivot_index + 1, high)

def partition(arr, low, high):
    """
    Partition function for Quick Sort.
    
    Args:
        arr: List to partition
        low: Starting index
        high: Ending index
        
    Returns:
        Final position of pivot
    """
    pivot = arr[high]
    i = low - 1
    
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def main():
    """Test the Quick Sort implementations."""
    test_arrays = [
        [64, 34, 25, 12, 22, 11, 90],
        [5, 2, 8, 1, 9, 3, 7, 4, 6],
        [1],
        [],
        [3, 3, 3, 3],
        [9, 8, 7, 6, 5, 4, 3, 2, 1]
    ]
    
    print("Quick Sort Algorithm Test")
    print("=" * 40)
    
    for i, arr in enumerate(test_arrays):
        print(f"\nTest Case {i + 1}:")
        print(f"Original: {arr}")
        
        # Create copies for different implementations
        arr_copy1 = arr.copy()
        arr_copy2 = arr.copy()
        
        # Standard Quick Sort
        sorted_arr1 = quick_sort(arr_copy1)
        print(f"Quick Sort: {sorted_arr1}")
        
        # In-place Quick Sort
        quick_sort_inplace(arr_copy2)
        print(f"In-place Quick Sort: {arr_copy2}")
        
        # Verify both give same result
        if sorted_arr1 == arr_copy2:
            print("✅ Both implementations match!")
        else:
            print("❌ Implementations differ!")

if __name__ == "__main__":
    main()
