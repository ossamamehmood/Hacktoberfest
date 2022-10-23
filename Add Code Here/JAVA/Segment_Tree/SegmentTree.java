class RangeQuery {

    private class SegmentTreeNode {
    
        private int start, end;
        private SegmentTreeNode left, right;
        private int sum;
    
        SegmentTreeNode(int start, int end) {
            this.start = start;
            this.end = end;
            this.left = null;
            this.right = null;
            this.sum = 0;
        }
    
    }

    private SegmentTreeNode root;

    RangeQuery(int[] arr) {
        this.root = buildTree(arr, 0, arr.length - 1);
    }

    private SegmentTreeNode buildTree(int[] arr, int start, int end) {

        if(start > end) {

            return null;
            
        } else {
            
            SegmentTreeNode node = new SegmentTreeNode(start, end);
            
            if(start == end) {
                node.sum = arr[start]; 
            } else {
                int mid = start + (end - start) / 2;
                node.left = buildTree(arr, start, mid);
                node.right = buildTree(arr, mid + 1, end);
                node.sum = node.left.sum + node.right.sum;
            }

            return node;
        }

    }

    public void update(int index, int val) {
        update(root, index, val);
    }

    private void update(SegmentTreeNode root, int index, int val) {
        
        if(root.start == root.end) {

            root.sum = val;

        } else {
            
            int mid = root.start + (root.end - root.start) / 2;

            if(index <= mid)
                update(root.left, index, val);
            else
                update(root.right, index, val);

            root.sum = root.left.sum + root.right.sum;
        }
    }

    public int rangeSum(int start, int end) {
        return rangeSum(root, start, end);
    }

    private int rangeSum(SegmentTreeNode root, int start, int end) {

        if(root.end == end && root.start == start) {

            return root.sum;

        } else {

            int mid = root.start + (root.end - root.start) / 2;

            int sum;

            if(end <= mid)
                sum =  rangeSum(root.left, start, end);
            else if(start >= mid + 1)
                sum =  rangeSum(root.right, start, end);
            else
                sum = rangeSum(root.left, start, mid) + rangeSum(root.right, mid + 1, end);

            return sum;

        }

    }



}
