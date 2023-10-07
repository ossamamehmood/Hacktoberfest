import networkx as nx
import matplotlib.pyplot as plt

# Create a sample graph
G = nx.DiGraph()
G.add_edges_from([(0, 1, {'weight': 4}), (0, 7, {'weight': 8}), (1, 7, {'weight': 11}),
                  (1, 2, {'weight': 8}), (7, 8, {'weight': 7}), (7, 6, {'weight': 1}),
                  (8, 6, {'weight': 6}), (2, 8, {'weight': 2}), (2, 3, {'weight': 7}),
                  (2, 5, {'weight': 4}), (6, 5, {'weight': 2}), (3, 5, {'weight': 14}),
                  (3, 4, {'weight': 9}), (4, 5, {'weight': 10})])

# Compute shortest paths using Bellman-Ford algorithm
shortest_path_lengths = nx.single_source_bellman_ford(G, source=0)[0]

# Create a visual representation of the graph with the shortest paths highlighted
pos = nx.spring_layout(G)  # Positioning for visualization
edge_labels = {(u, v): d['weight'] for u, v, d in G.edges(data=True)}
labels = {v: v for v in G.nodes()}

plt.figure(figsize=(10, 6))
nx.draw(G, pos, with_labels=True, labels=labels, node_color='lightblue', font_size=10)
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)

for target_node, path_length in shortest_path_lengths.items():
    if target_node != 0:
        shortest_path = nx.shortest_path(G, source=0, target=target_node)
        shortest_path_edges = [(shortest_path[i], shortest_path[i + 1]) for i in range(len(shortest_path) - 1)]
        nx.draw_networkx_edges(G, pos, edgelist=shortest_path_edges, edge_color='r', width=2,
                               label=f"Shortest Path to {target_node}")

plt.legend(loc='upper left')
plt.title("Shortest Paths (Bellman-Ford Algorithm)")
plt.show()
