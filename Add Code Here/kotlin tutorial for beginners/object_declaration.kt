fun main() {
println(a.num)
    println(b.p)
    println(b.test())
}

object a{
    val num : Int  = 10
}

object b{
val p : Int = 20
    fun test (){
        println("I am Object 8 ")
    }
}