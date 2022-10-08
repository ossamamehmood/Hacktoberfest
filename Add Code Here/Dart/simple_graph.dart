import 'vertex.dart';

/// A Graph Type
class SimpleGraph<T> {
  final Set<Vertex<T>> _vertices;

  /// Vertices of this graph
  List<Vertex<T>> get vertices => List<Vertex<T>>.unmodifiable(_vertices);

  /// Settings for this graph
  /// Is this a Digraph?
  final bool isDigraph;

  /// Create a new graph
  SimpleGraph({this.isDigraph = true}) : _vertices = <Vertex<T>>{};

  /// Total number of vertices for this graph
  int get numberOfVertices => _vertices.length;

  /// Total number of edges
  int get numberOfEdges =>
      _vertices.map((v) => v.outDegree).fold(0, (a, b) => a + b);

  /// Adds an edge
  void addEdge(Vertex<T> src, Vertex<T> dst, [num weight = 1]) {
    unlockVertices(<Vertex>{src, dst});
    if (src.key == dst.key) throw Error();

    src = _getOrAddVertex(src);
    dst = _getOrAddVertex(dst);
    src.addConnection(dst, weight);

    if (!isDigraph) dst.addConnection(src, weight);
    lockVertices(<Vertex>{src, dst});
  }

  /// Removes an Edge from [this], returns `false` if edge does not exists.
  bool removeEdge(Vertex src, Vertex dst) {
    unlockVertices(<Vertex>{src, dst});
    var removed = src.removeConnection(dst);
    lockVertices(<Vertex>{src, dst});

    return removed;
  }

  /// Checks if vertex is included
  bool containsVertex(Vertex vertex) => _vertices.contains(vertex);

  /// Checks if this is a null graph
  bool get isNull => numberOfVertices == 0;

  /// Checks if this is a singleton graph
  bool get isSingleton => numberOfVertices == 1;

  /// Checks if this is an empty graph
  bool get isEmpty => numberOfEdges == 0;

  /// Adds a new vertex
  bool addVertex(Vertex<T> vertex) => _vertices.add(vertex);

  /// Removes a vertex
  bool removeVertex(Vertex vertex) {
    var edgesRemoved = vertices.contains(vertex)
        ? [
            ...vertex.outgoingConnections.entries.map((e) => [vertex, e.key]),
            ...vertex.incomingVertices.map((e) => [e, vertex])
          ].fold(true, (bool acc, v) => acc && removeEdge(v[0], v[1]))
        : false;
    return edgesRemoved ? _vertices.remove(vertex) : edgesRemoved;
  }

  Vertex<T> _getOrAddVertex(Vertex<T> vertex) =>
      _vertices.add(vertex) ? vertex : vertex;

  /// Gets an edge list for [this].
  List<List> get edges => [
        for (var vertex in _vertices) ...[
          for (var connection in vertex.outgoingConnections.entries)
            [vertex, connection.key, connection.value]
        ]
      ];
}