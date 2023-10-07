fun main() {
var ph = opnPlus()
    ph.display()
    println(ph.name)
    println(ph.size)
    println(ph.toString())
}

open class mobile (){
   open var name :String = ""
    open var size:Int = 5
    fun makecall() = println("Making a call")
    fun poweerOff() = println("Shutting Down")
   open fun display()= println("simple mobile display")
}

class opnPlus :mobile ()
{
    override var name: String = "ONE PLUSE"
    override var size: Int = 6

    override fun display() {
        super.display()
        println("onrplus display")
    }

    override fun toString(): String {
        return " $name = one plus  size = $size inch"
    }

}