#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int>& parent) {
    if(parent[node] != node)
        parent[node] = findParent(parent[node], parent);
    return parent[node];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    
    if(rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
        if(rank[u] == rank[v])
            rank[v]++;
    }
}

vector<Edge> kruskalMST(int n, vector<Edge>& edges) {
    vector<Edge> mst;
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    
    sort(edges.begin(), edges.end(), compareEdges);
    
    for(Edge e : edges) {
        if(findParent(e.u, parent) != findParent(e.v, parent)) {
            mst.push_back(e);
            unionSets(e.u, e.v, parent, rank);
        }
    }
    
    return mst;
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        cout << "Enter edge from u to v and its weight (u v w): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    vector<Edge> mst = kruskalMST(n, edges);
    
    cout << "Minimum Spanning Tree Edges:\n";
    int totalWeight = 0;
    for(Edge e : mst) {
        cout << e.u << " - " << e.v << " (" << e.weight << ")\n";
        totalWeight += e.weight;
    }
    
    cout << "Total MST weight: " << totalWeight << endl;
    
    return 0;
}