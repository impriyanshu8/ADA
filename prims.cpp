#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<climits>
#include<algorithm>

using namespace std;

vector<pair<int,int>> primMST(int n, vector<pair<int,int>> adj[]) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> key(n+1, INT_MAX);
    vector<bool> inMST(n+1, false);
    vector<int> parent(n+1, -1);
    
    int start = 1; // Start from node 1 (can be any node)
    key[start] = 0;
    pq.push({0, start});
    
    vector<pair<int,int>> mstEdges;
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if(inMST[u]) continue;
        inMST[u] = true;
        
        if(parent[u] != -1) {
            mstEdges.push_back({parent[u], u});
        }
        
        for(auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if(!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    return mstEdges;
}

void createAdjacencyList(int m, vector<pair<int,int>> adj[]) {
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Enter edge from u to v and its weight (u v w): ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected edge
    }
    // kjjhjh
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    
    vector<pair<int,int>> adj[n+1]; // 1-based indexing
    createAdjacencyList(m, adj);
    
    vector<pair<int,int>> mst = primMST(n, adj);
    
    cout << "Minimum Spanning Tree Edges:\n";
    int totalWeight = 0;
    for(auto edge : mst) {
        cout << edge.first << " - " << edge.second << endl;
        // To get total weight, we'd need to look up the weights in adj
        // For simplicity, we're just showing the edges here
    }
    
    return 0;
}