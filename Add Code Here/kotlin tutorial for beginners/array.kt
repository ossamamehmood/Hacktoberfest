fun main() {
    // implicitly declared
    var arr = arrayOf("one" , "two" ,"three")
    var arr1 = arrayOf(1,2,3)
    //explicitly declared
    var arr3:Array<Int> = arrayOf<Int>(1,2,3)

    // printing an array

    for (i in arr){
        println(i)
    }
    // printing array with index number

    for ((i ,e) in arr.withIndex()){
        println("$i -- $e")
    }
    // excessing array element
    println(arr[0])
    println(arr.get(1))

    //changing the element value

    println(arr.set(0,"Dayam"))
    println(arr[0])


}