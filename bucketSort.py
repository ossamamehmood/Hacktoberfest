


def bucketSort(array):
    bucket = []

  
    for i in range(len(array)):
        bucket.append([])

   
    for j in array:
        index_b = int(10 * j)
        bucket[index_b].append(j)

 
    for i in range(len(array)):
        bucket[i] = sorted(bucket[i])

    
    k = 0
    for i in range(len(array)):
        for j in range(len(bucket[i])):
            array[k] = bucket[i][j]
            k += 1
    return array


array = [.42, .32, .33, .52, .37, .47, .51]
print("Sorted Array in descending order is")
print(bucketSort(array))