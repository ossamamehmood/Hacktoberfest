fun main() {
var ob = child()
    ob.method1()
    ob.method2()
   println(ob.name)
}
// using open keyword to allow parent class to inherit
open class parent{
    var name :String = " cool "
    fun method1(){
        println("I am parent")
    }
}
// inherting parent class by using : operater
class child : parent(){
    var name2:String = ""
    fun method2(){
        println("I am Child")
    }
}