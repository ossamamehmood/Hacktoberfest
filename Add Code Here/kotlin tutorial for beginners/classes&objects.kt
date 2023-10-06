fun main() {
    // class car
     val maruti = car("swift", "petrol" , 100)
    val tata =  car ("nexon" , "electric" , 200)
   println(maruti.name)
    println(maruti.type)

    println(tata.name)
    println(tata.type)

    tata.driveCar()

    // class person

    val p1 = person("dayam" , 21)
    val p2 = person ("ayan" , 17)

    println(p1.name)
    println(p1.canVote())

    println(p2.name)
    println(p2.canVote())
}

class car (val name : String , val type : String ,var kmRan:Int)
{
    fun driveCar(){
        println("$name Car is driving")
    }
    fun applyBreak(){
        println("Applied Breaks ")
    }
}

class person(val name : String  , var age : Int ){
    // method
    fun canVote():Boolean{
        return age>18
    }
}