import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import cv2
import numpy as np

# Create a grid graph
G = nx.grid_2d_graph(5, 5)

# Create BFS traversal generator
def bfs_traversal(G, start):
    visited = set()
    queue = [start]
    while queue:
        node = queue.pop(0)
        if node not in visited:
            visited.add(node)
            yield node
            queue.extend(n for n in G.neighbors(node) if n not in visited)

# Create an animation of BFS traversal
fig, ax = plt.subplots()
pos = {node: node for node in G.nodes()}
visited_nodes = []

def update(frame):
    ax.clear()
    node = frame
    visited_nodes.append(node)
    nx.draw(G, pos, ax=ax, node_color='b', node_size=100)
    nx.draw(G.subgraph(visited_nodes), pos, ax=ax, node_color='r', node_size=100)
    ax.set_title(f'BFS Traversal Step {frame}')

ani = FuncAnimation(fig, update, frames=bfs_traversal(G, (0, 0)), repeat=False)
plt.show()

# Save the animation as a video
writer = cv2.VideoWriter('bfs_traversal.mp4', cv2.VideoWriter_fourcc(*'mp4v'), 5, (400, 400))
for frame in range(len(list(bfs_traversal(G, (0, 0))))):
    update(frame)
    fig.canvas.draw()
    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8').reshape(400, 400, 3)
    writer.write(image)

writer.release()

