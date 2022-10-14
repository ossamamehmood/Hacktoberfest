class Node<T> {
  const Node(this.value, {this.left, this.right});

  final T value;
  final Node<T>? left;
  final Node<T>? right;

  Node<T> inverted() => Node<T>(value, left: right?.inverted(), right: left?.inverted());

  @override
  String toString() {
    return '{value: ${value ?? ''}${left != null ? ', {left: $left}' : ''}${right != null ? ', {right: $right}' : ''}}';
  }
}

void main() {
  final leftSubtree = Node<int>(4, left: Node(6), right: Node(7));
  final rightSubtree = Node<int>(10, left: Node(8), right: Node(9));

  final tree = Node<int>(1, left: leftSubtree, right: rightSubtree);

  print(tree);
  print(tree.inverted());
}