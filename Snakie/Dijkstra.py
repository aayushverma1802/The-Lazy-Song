# Python program for the above approach
import heapq

# This class represents a directed graph using
# adjacency list representation
class Graph:
    def __init__(self, V):
        self.V = V  # No. of vertices
        self.adj = [[] for _ in range(V)]  # In a weighted graph, store vertex and weight pair for every edge

    # Function to add an edge to the graph
    def add_edge(self, u, v, w):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))

    # Prints shortest paths from src to all other vertices
    def shortest_path(self, src):
        # Create a priority queue to store vertices that
        # are being preprocessed.
        pq = [(0, src)]  # The first element of the tuple is the distance, and the second is the vertex label

        # Create a list for distances and initialize all
        # distances as infinite (INF)
        dist = [float('inf')] * self.V
        dist[src] = 0

        # Looping until the priority queue becomes empty
        while pq:
            # The first element in the tuple is the minimum distance vertex
            # Extract it from the priority queue
            current_dist, u = heapq.heappop(pq)

            # Iterate over all adjacent vertices of a vertex
            for v, weight in self.adj[u]:
                # If there is a shorter path to v through u
                if dist[v] > dist[u] + weight:
                    # Update the distance of v
                    dist[v] = dist[u] + weight
                    heapq.heappush(pq, (dist[v], v))

        # Print shortest distances
        print("Vertex Distance from Source")
        for i in range(self.V):
            print(f"{i}\t\t{dist[i]}")

# Driver program to test methods of the graph class
if __name__ == "__main__":
    # Create the graph given in the above figure
    V = 9
    g = Graph(V)

    # Making the above-shown graph
    g.add_edge(0, 1, 4)
    g.add_edge(0, 7, 8)
    g.add_edge(1, 2, 8)
    g.add_edge(1, 7, 11)
    g.add_edge(2, 3, 7)
    g.add_edge(2, 8, 2)
    g.add_edge(2, 5, 4)
    g.add_edge(3, 4, 9)
    g.add_edge(3, 5, 14)
    g.add_edge(4, 5, 10)
    g.add_edge(5, 6, 2)
    g.add_edge(6, 7, 1)
    g.add_edge(6, 8, 6)
    g.add_edge(7, 8, 7)

    g.shortest_path(0)

