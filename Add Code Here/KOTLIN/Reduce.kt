package br.com.alura.devhub

class Reduce {

    fun main() {
        val items = listOf(10, 20, 30)

        val sum = items.reduce { x, y -> x + y }

        println(sum)        
    }

}