#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, wt;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].wt;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    bool hasCycle = false;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int wt = edges[j].wt;
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) {
        cout << "Graph contains a negative weight cycle!" << endl;
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> " << dist[i] << endl;
        }
    }
}

int main() {
    int V = 5; // number of vertices
    int E = 8; // number of edges
    vector<Edge> edges(E);

    // Example: Add edges (u, v, weight)
    edges = {
        {0, 1, -1},
        {0, 2,  4},
        {1, 2,  3},
        {1, 3,  2},
        {1, 4,  2},
        {3, 2,  5},
        {3, 1,  1},
        {4, 3, -3}
    };

    int source = 0;
    bellmanFord(V, E, edges, source);

    return 0;
}
