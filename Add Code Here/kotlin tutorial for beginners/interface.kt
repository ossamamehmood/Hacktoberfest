import java.util.Objects

fun main() {
dragObject(arrayOf(xircle(4.0) , xrinagle(2.0,3.0) ,player("Dayam ")))
}
//before implementation interface
//fun dragObject(objects: Array<xhape>)

// after implementation interface
fun dragObject(objects: Array<Dragable>){
    for (obj:Dragable in objects){
        obj.drag()
    }
}
interface Dragable {
    fun drag()
}

abstract  class xhape :Dragable {
 abstract   fun area(): Double

}

// derived classes;;;;
class xircle (val radius: Double) : xhape(){
   override fun area(): Double = Math.PI * radius * radius
    override fun drag() {
          println("Circle is draging")
    }
}
class xrinagle (val base :Double , val height :Double) : xhape(){
    override fun area(): Double= 0.5* base *height
    override fun drag() {
       println("triangle is draging")
    }
}

class player(val name : String) : Dragable{
   override fun drag() = println("$name is Draging ")
}