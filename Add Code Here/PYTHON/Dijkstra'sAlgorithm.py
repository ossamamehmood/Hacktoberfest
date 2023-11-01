import heapq

class Graph:
    def __init__(self):
        self.vertices = set()
        self.edges = {}
    
    def add_edge(self, start, end, weight):
        self.vertices.add(start)
        self.vertices.add(end)
        if start in self.edges:
            self.edges[start].append((end, weight))
        else:
            self.edges[start] = [(end, weight)]

def dijkstra(graph, start):
    shortest_path = {vertex: float('infinity') for vertex in graph.vertices}
    shortest_path[start] = 0
    priority_queue = [(0, start)]

    while priority_queue:
        current_dist, current_vertex = heapq.heappop(priority_queue)

        if current_dist > shortest_path[current_vertex]:
            continue

        if current_vertex in graph.edges:
            for neighbor, weight in graph.edges[current_vertex]:
                distance = current_dist + weight
                if distance < shortest_path[neighbor]:
                    shortest_path[neighbor] = distance
                    heapq.heappush(priority_queue, (distance, neighbor))

    return shortest_path

def find_shortest_path(graph, start, end):
    distances = dijkstra(graph, start)
    path = [end]
    while end != start:
        for neighbor, _ in graph.edges[end]:
            if distances[neighbor] + graph.edges[neighbor][0][1] == distances[end]:
                path.append(neighbor)
                end = neighbor
                break
    return path[::-1]

if __name__ == "__main__":
    graph = Graph()
    graph.add_edge("A", "B", 1)
    graph.add_edge("A", "C", 4)
    graph.add_edge("B", "C", 2)
    graph.add_edge("B", "D", 5)
    graph.add_edge("C", "D", 1)
    graph.add_edge("D", "E", 3)

    start_vertex = "A"
    end_vertex = "E"

    shortest_path = find_shortest_path(graph, start_vertex, end_vertex)
    print("Shortest Path:", shortest_path)

