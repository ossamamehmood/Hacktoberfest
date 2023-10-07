// default constructor && lateinit

fun main() {
    val ob = calculator()
println(ob.add(2,4))
    var p1 = person1("dayam" ,20)
    p1.age = 30
    p1.age =-12
    println(p1.name)
    println(p1.age)
}

class calculator {
    lateinit var message :String
    fun add(a: Int, b: Int): Int {
        return a + b
    }


    fun multiply(a: Int, b: Int): Int {
        return a * b
    }

}

class person1(namep:String , agep:Int){
    var name:String = namep
        get() {
            println("Name getter is called")
            return field.toUpperCase()
        }
    var age:Int = agep
        set(value) {
            if (value>0){
                field = value
            }
            else{
                println("Age can't be negative")
            }
        }


}