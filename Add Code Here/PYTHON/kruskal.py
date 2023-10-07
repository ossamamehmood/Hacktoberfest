import networkx as nx
import matplotlib.pyplot as plt

# Create a sample graph
G = nx.Graph()
G.add_edges_from([(0, 1, {'weight': 4}), (0, 7, {'weight': 8}), (1, 7, {'weight': 11}),
                  (1, 2, {'weight': 8}), (7, 8, {'weight': 7}), (7, 6, {'weight': 1}),
                  (8, 6, {'weight': 6}), (2, 8, {'weight': 2}), (2, 3, {'weight': 7}),
                  (2, 5, {'weight': 4}), (6, 5, {'weight': 2}), (3, 5, {'weight': 14}),
                  (3, 4, {'weight': 9}), (4, 5, {'weight': 10})])

# Kruskal's algorithm
mst = nx.minimum_spanning_tree(G)

# Create a visual representation of the graph with the MST highlighted
pos = nx.spring_layout(G)  # Positioning for visualization
edge_labels = {(u, v): d['weight'] for u, v, d in G.edges(data=True)}
labels = {v: v for v in G.nodes()}

plt.figure(figsize=(10, 6))
nx.draw(G, pos, with_labels=True, labels=labels, node_color='lightblue', font_size=10)
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)
nx.draw(mst, pos, edge_color='r', width=2)
plt.title("Minimum Spanning Tree (Kruskal's Algorithm)")
plt.show()

