fun main() {
    val vowel = arrayOf('a', 'i', 'u', 'e', 'o')
    val consonant = arrayOf('b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'y', 'z')
    
    for (i in 0..5) {
        if (i % 2 == 0) print(consonant[(0..consonant.size-1).random()])
        else print(vowel[(0..vowel.size-1).random()])
    }
}
