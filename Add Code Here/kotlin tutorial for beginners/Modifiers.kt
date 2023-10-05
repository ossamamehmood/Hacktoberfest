fun main() {
val hh = B()
    println(hh.p)

}

open class A {
    public var p = 10
    private var q =20
    internal var r = 30
    protected var s = 40

}

class B : A(){
    fun test(){
        println(p)
        // because c is private 
       // println(q)
        println(r)
        println(s)

    }
}