#include <iostream>
#include <vector>
#include<cmath>
#include <climits> // For INT_MAX

using namespace std;

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph;
    // comments

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // Only proceed if both distances are not "infinity"
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
        }
    }
}
    }

    // Output the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0,       5,       INT_MAX, 10},
        {INT_MAX, 0,       3,       INT_MAX},
        {INT_MAX, INT_MAX, 0,       1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    floydWarshall(graph, V);

    return 0;
}
