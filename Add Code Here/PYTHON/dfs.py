import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import cv2

# Create a grid graph
G = nx.grid_2d_graph(5, 5)

# Create DFS traversal generator
def dfs_traversal(G, start):
    visited = set()
    stack = [start]
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            yield node
            neighbors = list(G.neighbors(node))
            neighbors.reverse()  # Reverse the order for visualization
            stack.extend(n for n in neighbors if n not in visited)

# Create an animation of DFS traversal
fig, ax = plt.subplots()
pos = {node: node for node in G.nodes()}
visited_nodes = []

def update(frame):
    ax.clear()
    node = frame
    visited_nodes.append(node)
    nx.draw(G, pos, ax=ax, node_color='b', node_size=100)
    nx.draw(G.subgraph(visited_nodes), pos, ax=ax, node_color='r', node_size=100)
    ax.set_title(f'DFS Traversal Step {frame}')

ani = FuncAnimation(fig, update, frames=dfs_traversal(G, (0, 0)), repeat=False)
plt.show()

# Save the animation as a video
writer = cv2.VideoWriter('dfs_traversal.mp4', cv2.VideoWriter_fourcc(*'mp4v'), 5, (400, 400))
for frame in range(len(list(dfs_traversal(G, (0, 0))))):
    update(frame)
    fig.canvas.draw()
    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8').reshape(400, 400, 3)
    writer.write(image)

writer.release()
