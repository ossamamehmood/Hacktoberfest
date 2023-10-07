fun main() {
    var car = Automobile("car ",4,6,true) // object creation
    var pm = Person("dayam" , 21)
    println(pm.name)
    println(pm.age)
    var pm2 = Person("Ayan" ,20)
    println(pm2.name)
    println(pm2.age)
    println(car.airbags)


}

class Automobile(val name:String , val tyers:Int , val maxsitting:Int ,hasairbags:Boolean){
    var airbags = hasairbags
    fun drive(){}
    fun applyBreak(){}
}

class empty{}

class Person(nameParam:String , ageParam:Int){
    val name:String = "$nameParam boss"
    var age :Int = ageParam
}

