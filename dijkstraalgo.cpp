#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<climits>
#include<algorithm>

using namespace std;

vector<int> dijkstraAlgo(int n , vector<pair<int, int>> adj[], int s) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int neighbour = it.first;
            int edgeweight = it.second;

            if(distance + edgeweight < dist[neighbour]) {
                dist[neighbour] = distance + edgeweight;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}

void createAdjacencyList(int m, vector<pair<int, int>> adj[]) {
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Enter edge from u to v and its weight (u v w): ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Directed edge
    }
}

int main() {
    int n, m, start;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<pair<int, int>> adj[n + 1]; // 1-based indexing
    createAdjacencyList(m, adj);

    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distances = dijkstraAlgo(n, adj, start);

    cout << "Shortest distances from node " << start << ":\n";
    for(int i = 1; i <= n; i++) {
        cout << "Node " << i << ": ";
        if(distances[i] == INT_MAX) cout << "INF";
        else cout << distances[i];
        cout << endl;
    }

    return 0;
}
// done