package br.com.alura.devhub

class SummaryStat {

    fun main() {
        val items = listOf(10, 20, 30)

        val sum = items.stream().mapToInt { it }.summaryStatistics().sum

        println(sum)         // 60
    }
}