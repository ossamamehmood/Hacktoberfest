<<<<<<< HEAD:bucketSort.py
# Bucket Sort in Python
=======

>>>>>>> 94a4bca07f2b0d8e32946fbb00433c2b9ae95e43:Add Code Here/PYTHON/bucketSort.py


def bucketSort(array):
    bucket = []

<<<<<<< HEAD:bucketSort.py
    # Create empty buckets
    for i in range(len(array)):
        bucket.append([])

    # Insert elements into their respective buckets
=======
  
    for i in range(len(array)):
        bucket.append([])

   
>>>>>>> 94a4bca07f2b0d8e32946fbb00433c2b9ae95e43:Add Code Here/PYTHON/bucketSort.py
    for j in array:
        index_b = int(10 * j)
        bucket[index_b].append(j)

<<<<<<< HEAD:bucketSort.py
    # Sort the elements of each bucket
    for i in range(len(array)):
        bucket[i] = sorted(bucket[i])

    # Get the sorted elements
=======
 
    for i in range(len(array)):
        bucket[i] = sorted(bucket[i])

    
>>>>>>> 94a4bca07f2b0d8e32946fbb00433c2b9ae95e43:Add Code Here/PYTHON/bucketSort.py
    k = 0
    for i in range(len(array)):
        for j in range(len(bucket[i])):
            array[k] = bucket[i][j]
            k += 1
    return array


array = [.42, .32, .33, .52, .37, .47, .51]
print("Sorted Array in descending order is")
print(bucketSort(array))