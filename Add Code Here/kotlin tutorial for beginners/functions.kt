fun main() {
    var result = add(5,10)
    println(result)
    oddEven(13)
    oddEven(24)
    var x = add2(55,100)
    println(x)
    printmsg(4)
    // function will take default value if i will not pass any of the argument
    printmsg()


}
fun add (num1 :Int , num2:Int):Int
{
    var sum =  num1+num2
    return sum
}
fun oddEven(num3 :Int){
    var ans = if (num3 % 2 == 0) "Even" else "odd"
    println(ans)

}
// in line function means defining the function in one line
fun add2 (num5 :Int , num4 :Int ):Int =num5+num4

// default argument concept
fun printmsg(count :Int = 2){
    for (i in 1..count){
        println("Hello Dayam $i")
    }
}