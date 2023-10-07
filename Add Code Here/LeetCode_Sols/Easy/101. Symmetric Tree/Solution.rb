def is_symmetric(root)
    return true if root.nil?
    queue = [root.left, root.right]
    while !queue.empty?
        left = queue.shift
        right = queue.shift
        return false if left.nil? && !right.nil? || !left.nil? && right.nil?
        return false if !left.nil? && !right.nil? && left.val != right.val
        queue.push(left.left) if !left.nil?
        queue.push(right.right) if !right.nil?
        queue.push(left.right) if !left.nil?
        queue.push(right.left) if !right.nil?
    end
    true
end
