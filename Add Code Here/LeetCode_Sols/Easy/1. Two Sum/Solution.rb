def two_sum(nums, target)
    hash = {}
    nums.each_with_index do |num, idx|
        complement = target - num
        return [hash[complement], idx] if hash.key?(complement)
        hash[num] = idx
    end
end