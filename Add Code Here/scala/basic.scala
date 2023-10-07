object BasicScalaScript {
  def main(args: Array[String]): Unit = {
    // This is the entry point of the script
    println("Hello, Scala!") // Print a message to the console
    
    // Variables and Data Types
    val a: Int = 10 // Immutable variable
    var b: String = "Hello" // Mutable variable
    val c = 3.14 // Type inference
    
    // Control Structures
    if (a > 5) {
      println("a is greater than 5")
    } else {
      println("a is not greater than 5")
    }
    
    for (i <- 1 to 5) {
      println(s"Loop iteration $i")
    }
    
    // Functions
    def add(x: Int, y: Int): Int = {
      x + y
    }
    
    val result = add(3, 4)
    println(s"3 + 4 = $result")
    
    // Collections
    val myList = List(1, 2, 3, 4, 5)
    val doubledList = myList.map(_ * 2)
    println(s"Doubled list: $doubledList")
    
    // Pattern Matching
    val day = "Monday"
    val dayType = day match {
      case "Monday" | "Tuesday" | "Wednesday" | "Thursday" | "Friday" => "Weekday"
      case "Saturday" | "Sunday" => "Weekend"
      case _ => "Unknown"
    }
    println(s"Today is a $dayType")
  }
}
