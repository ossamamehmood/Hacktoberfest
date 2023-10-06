class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val = 0, left = nil, right = nil)
        @val = val
        @left = left
        @right = right
    end
end

def inorder_traversal(root)
    result = []
    stack = []
    current = root
    while current || stack.length > 0
        while current
            stack.push(current)
            current = current.left
        end
        current = stack.pop()
        result << current.val
        current = current.right
    end
    result
end