class Solution {
    public int hIndex(int[] citations) {
        // Initialize the search range
        int start = 0;
        int end = citations.length - 1;
        
        // Perform a binary search
        while (start <= end) {
            // Calculate the middle index
            int mid = start + (end - start) / 2;
            
            // Calculate the number of papers with citations greater than or equal to citations[mid]
            int number_of_papers = citations.length - mid;
            
            // Check if citations[mid] is greater than the number of papers with citations greater than or equal to it
            if (citations[mid] > number_of_papers) {
                end = mid - 1; // Reduce the search range to the left half
            } else if (citations[mid] < number_of_papers) {
                start = mid + 1; // Reduce the search range to the right half
            } else {
                // If citations[mid] is equal to the number of papers, it's a valid H-index
                return citations[mid];
            }
        }
        
        // Calculate the H-index based on the final position of 'end'
        return citations.length - (end + 1);
    }
}
