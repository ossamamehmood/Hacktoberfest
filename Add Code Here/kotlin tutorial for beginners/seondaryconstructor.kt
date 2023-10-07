fun main() {
    var car = Automobile1("car","petrol")
    println(car.maxsitting)
}

class Automobile1(val name:String , val tyers:Int , val maxsitting:Int ,val engineType:String){
    // initializer Blocks
    init {
        println("$name is created")
    }
    constructor(name:String , engineType: String):
            this(name ,4 ,5 ,engineType)



}