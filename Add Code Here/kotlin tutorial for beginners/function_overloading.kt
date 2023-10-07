fun main() {
println(addition(6,5))

    // function as a variable 
   val fn = ::addition2
    println(fn(5.2,9.6))
    // nailed
    println(addition(a = 6 ,b =20))
}
fun addition (a :Int , b:Int):Int{
    return a+b
}
fun addition2 (a : Double , b: Double):Double{
    return a+b
}