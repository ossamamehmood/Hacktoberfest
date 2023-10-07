fun main() {
val cr = rircle(4.50);
    println(cr.area())
    cr.display()
}
abstract  class whape {
    var mane :String = " "
    abstract fun area() : Double
  abstract fun display()
}
// child class
class rircle (val radius:Double):whape(){
    override fun area ():Double = Math.PI * radius * radius
    override fun display() {
       println("circle is getting displayed ")
    }


}