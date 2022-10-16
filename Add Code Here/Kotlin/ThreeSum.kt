package br.com.alura.devhub

class ThreeSum {

    fun threeSum(nums: IntArray): List<List<Int>> {
        val result: MutableList<List<Int>> = mutableListOf()
        val sortedNum = nums.sorted()

        sortedNum
                .forEachIndexed { index, i ->
                    twoSumOptimized(
                            sortedNum.toMutableList().subList(index.inc(), nums.size).toIntArray(),
                            -i
                    )
                            .run {
                                this.forEach {
                                    it.toMutableList()
                                            .apply { this.add(i) }
                                            .sorted().let {
                                                if (!result.contains(it)) {
                                                    result.add(it)
                                                }
                                            }
                                }
                            }
                }
        return result
    }


    fun twoSumOptimized(nums: IntArray, target: Int): List<List<Int>> {
        val diff = mutableMapOf<Int, Int>()
        val result: MutableList<MutableList<Int>> = mutableListOf()

        nums.forEachIndexed { index, i ->
            diff[i]?.let { result.add(mutableListOf(nums.get(it), nums.get(index))) }
            diff[target - i] = index
        }

        return result
    }

}