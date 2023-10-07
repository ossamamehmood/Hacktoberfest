fun main() {
    for (i in 1..5){
        println(i)
    }
// increment by 2
    for (i in 1..5 step 2) {
        println(i)
    }

    println("until")
    for (i in 1 until 5){
        println(i)
    }

    for(i in 10 downTo 1){
        println(i)
    }
    // question
    val number = 2
    for (i in 1..10){
        println("$number X $i = " + number * i)
    }

}