bubble_sort <- function(x)
{
    # calculate the length of array
    n <- length(x)
             # run loop n-1 times
        for (i in 1 : (n - 1)) {
              # run loop (n-i) times
            for (j in 1 : (n - i)) {
                  # compare elements
                if (x[j] > x[j + 1]) {
                    temp <- x[j]
                      x[j] <- x[j + 1]
                      x[j + 1] <- temp
                }
            }
        }
      x
}
 
# 10 random numbers between 1 - 100
arr <- sample(1 : 100, 10)
 
# sort the array and store the result
# in sorted_array
sorted_array <- bubble_sort(arr)
 
# print sorted_array
sorted_array