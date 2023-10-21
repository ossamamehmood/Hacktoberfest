function linear_search(arr, target)
    for (index, value) in enumerate(arr)
        if value == target
            return index  # Return the index if the target is found
        end
    end
    return -1  # Return -1 if the target is not found in the array
end

# Example usage
arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
target = 6
result = linear_search(arr, target)

if result == -1
    println("$target not found in the array.")
else
    println("$target found at index $result.")
end
