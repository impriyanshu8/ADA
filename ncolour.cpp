#include <iostream>
#include <vector>
using namespace std;

#define V 4 // Number of vertices in the graph

// Function to check if the current color assignment is safe for vertex
bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive utility function to solve the problem
bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // Backtrack
            color[v] = 0;
        }
    }
    return false;
}

// Main function to solve the N-Coloring problem
bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> color(V, 0);

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist." << endl;
        return false;
    }

    cout << "Solution Exists: Following are the assigned colors:" << endl;
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;

    return true;
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}
