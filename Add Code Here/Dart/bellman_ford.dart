import 'dart:collection';

import 'simple_graph.dart';
import 'vertex.dart';

/// Run the Bellman Ford algorithm to get the shortest paths from [source] to
/// all vertices.
HashMap<Vertex, num>? bellmanFord(SimpleGraph graph, Vertex source) {
  var distances = HashMap<Vertex, num>();
  distances[source] = 0;

  var edges = graph.edges;
  var counter = graph.numberOfVertices - 1;

  bool shouldUpdate(Vertex u, Vertex v, num w) {
    if (!distances.containsKey(u)) return false;
    var uValue = distances[u]!;
    var vValue = distances[v] ?? (uValue + w + 1);

    return uValue + w < vValue;
  }

  while (counter > 0) {
    for (var edge in edges) {
      var u = edge[0];
      var v = edge[1];
      var w = edge[2];
      if (shouldUpdate(u, v, w)) {
        distances[v] = distances[u]! + w;
      }
    }

    counter--;
  }

  for (var edge in edges) {
    var u = edge[0];
    var v = edge[1];
    var w = edge[2];
    if (shouldUpdate(u, v, w)) {
      return null;
    }
  }

  return distances;
}