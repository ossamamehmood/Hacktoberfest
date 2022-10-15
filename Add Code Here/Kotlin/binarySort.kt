package main.algorithms.searching

fun main(args: Array<String>) {
    val input = readLine()!!.trim().split(" ").map { it -> it.toInt() }.toIntArray()    // to read an array (from user input)
    val eleToSearch = readLine()!!.trim().toInt()   // to read the element to be searched (from user input)
    val pos = binarySearchRecursive(input, eleToSearch, 0, input.size -1)
    if(pos >= 0 ) {
        println(pos)    // to print position at last
    } else {
        println("Position not found")
    }
}

fun binarySearchRecursive(input: IntArray, eleToSearch: Int, low:Int, high:Int): Int {

    while(low <=high) {
      val mid = (low + high) /2
        when {
            eleToSearch > input[mid] -> return binarySearchRecursive(input, eleToSearch, mid+1, high)   // element is greater than middle element of array, so it will be in right half. Recursion will call the right half again
            eleToSearch < input[mid] -> return binarySearchRecursive(input, eleToSearch, low, mid-1)    //element is less than middle element of array, so it will be in left half of the array. Recursion will call the left half again.
            eleToSearch == input[mid] -> return mid // element found.
        }
    }
    return -1
}
