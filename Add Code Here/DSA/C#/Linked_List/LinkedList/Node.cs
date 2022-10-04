namespace LinkedList
{
    public class Node {
        private int _data;
        private Node _next;
        public Node(int data)
        {
            this._data = data;
            this._next = null;
        }
        public Node Next
        {
            get{ return _next; }
            set { _next = value; }
        }
        public int Data
        {
            get{ return _data; }
            set { _data = value; }
        }
    }
}
