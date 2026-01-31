class PriorityQueue {
    constructor() {
        this.queue = [];
    }

    enqueue(element) {
        this.queue.push(element);
        this.queue.sort((a, b) => a[0] - b[0]);
    }

    dequeue() {
        if (this.isEmpty()) return "Queue is empty";
        return this.queue.shift();
    }

    isEmpty() {
        return this.queue.length === 0;
    }
}

class Graph {
    constructor(V) {
        this.V = V;
        this.adj = new Array(V).fill().map(() => []);
    }

    addEdge(u, v, w) {
        this.adj[u].push([v, w]);
        this.adj[v].push([u, w]);
    }

    shortestPath(src) {
        const pq = new PriorityQueue();
        const dist = new Array(this.V).fill(Infinity);

        pq.enqueue([0, src]);
        dist[src] = 0;

        while (!pq.isEmpty()) {
            const [uDist, u] = pq.dequeue();

            for (const [v, weight] of this.adj[u]) {
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.enqueue([dist[v], v]);
                }
            }
        }

        console.log("Vertex Distance from Source");
        for (let i = 0; i < this.V; ++i) {
            console.log(i + "\t\t" + dist[i]);
        }
    }
}

// Driver program to test methods of the graph class
function main() {
    // create the graph given in the provided C++ code
    const V = 9;
    const g = new Graph(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);
}

// Call the main function
main();