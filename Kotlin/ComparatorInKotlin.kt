val students = mutableListOf(21 to "Helen", 21 to "Tom", 20 to "Jim") 

val ageComparator = compareBy<Pair<Int, String?>> {it.first}
val ageAndNameComparator = ageComparator.thenByDescending {it.second}
println(students.sortedWith(ageAndNameComparator))
