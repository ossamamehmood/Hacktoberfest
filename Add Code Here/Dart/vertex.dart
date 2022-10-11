import 'dart:collection';

/// A vertex of a [Graph]. A vertex contains a `key` uniquely identifying it.
/// Value is optional, it is used when complex data structure may be attached to
/// the vertex. By default, the `key` and `value` are the same.
class Vertex<T> {
  final String _key;
  bool _isLocked;

  /// Uniquely identifiable key to this [Vertex]
  String get key => _key;

  /// Optional value
  T? value;

  final LinkedHashSet<Vertex> _incomingVertices;

  /// Incoming connections from this [Vertex]
  List<Vertex> get incomingVertices =>
      List<Vertex>.unmodifiable(_incomingVertices);

  final LinkedHashMap<Vertex, num> _outgoingConnections;

  /// Outgoing connections from this [Vertex]
  Map<Vertex, num> get outgoingConnections =>
      Map<Vertex, num>.unmodifiable(_outgoingConnections);

  /// Constructor
  Vertex(this._key, [this.value])
      : _isLocked = true,
        _incomingVertices = <Vertex>{} as LinkedHashSet<Vertex>,
        _outgoingConnections = <Vertex, num>{} as LinkedHashMap<Vertex, num>;

  /// Lock [this] vertex, cannot modify after it is locked
  void lock() => _isLocked = true;

  /// Unlock [this] vertex, can modify after it is unlock
  void unlock() => _isLocked = false;

  /// Adds a connection with [Vertex] `dst` and with `weight`
  bool addConnection(Vertex dst, [num weight = 1]) {
    if (_isLocked || dst._isLocked) {
      throw UnsupportedError('Cannot add to a locked vertex');
    }
    if (_outgoingConnections.containsKey(dst)) {
      return false;
    }
    _outgoingConnections[dst] = weight;
    dst._incomingVertices.add(this);
    return true;
  }

  /// Removes a connection with `other` with `weight`. `false` for non-existent
  /// connection.
  bool removeConnection(Vertex other, [num weight = 1]) {
    if (_isLocked || other._isLocked) {
      throw UnsupportedError('Cannot remove from a locked vertex');
    }
    var outgoingRemoved = _outgoingConnections.remove(other) != null;
    var incomingRemoved = other._incomingVertices.remove(this);

    return outgoingRemoved && incomingRemoved;
  }

  /// Checks if [Vertex] `other` is connected to this vertex
  bool containsConnectionTo(Vertex other) =>
      _outgoingConnections.containsKey(other);

  /// Checks if [Vertex] `other` is connected to this vertex
  bool containsConnectionFrom(Vertex other) =>
      _incomingVertices.contains(other);

  /// Get a list of adjacent outgoing vertices
  Set<Vertex> get outgoingVertices =>
      _outgoingConnections.keys.map((connection) => connection).toSet();

  /// Is this vertex isolated?
  bool get isIsolated => _outgoingConnections.isEmpty;

  /// Calculate the inDegree of the vertex
  int get inDegree => _incomingVertices.length;

  /// Calculate the outDegree of the vertex
  int get outDegree => _outgoingConnections.length;

  @override
  String toString() => key;

  // ignore: avoid_equals_and_hash_code_on_mutable_classes
  bool operator ==(Object other) => other is Vertex && key == other.key;

  // ignore: avoid_equals_and_hash_code_on_mutable_classes
  int get hashCode => key.hashCode;
}

/// Unlocks a set of vertices
void unlockVertices(Set<Vertex> vertices) {
  for (var vertex in vertices) {
    vertex.unlock();
  }
}

/// Locks a set of vertices
void lockVertices(Set<Vertex> vertices) {
  for (var vertex in vertices) {
    vertex.lock();
  }
}