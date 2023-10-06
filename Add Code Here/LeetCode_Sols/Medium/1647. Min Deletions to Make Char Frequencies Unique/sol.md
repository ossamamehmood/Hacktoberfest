Create an array to store the frequency of each character in the string.
Sort the frequencies in ascending order.
Initialize the deletion count to zero.
Iterate over the frequencies in reverse order.
If the current frequency is equal to or greater than the next frequency, then decrement the current frequency by the maximum of zero and the next frequency minus one. Update the deletion count by the difference between the previous and current frequencies.
Return the deletion count.


his algorithm works by greedily reducing the frequency of the most common characters until all frequencies are distinct. This ensures that the minimum number of deletions is required to achieve a unique frequency distribution.