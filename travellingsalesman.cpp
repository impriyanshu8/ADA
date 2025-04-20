#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findNextCity(vector<vector<int>>& graph, vector<bool>& visited, int currentCity) {
    int minDist = INT_MAX;
    int nextCity = -1;
    
    for (int city = 0; city < graph.size(); city++) {
        if (!visited[city] && graph[currentCity][city] < minDist && graph[currentCity][city] != 0) {
            minDist = graph[currentCity][city];
            nextCity = city;
        }
    }
    return nextCity;
}

vector<int> tspGreedy(vector<vector<int>>& graph, int startCity) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> path;
    int currentCity = startCity;
    
    visited[currentCity] = true;
    path.push_back(currentCity);
    
    for (int i = 0; i < n - 1; i++) {
        int nextCity = findNextCity(graph, visited, currentCity);
        if (nextCity == -1) break;
        
        visited[nextCity] = true;
        path.push_back(nextCity);
        currentCity = nextCity;
    }
    
    path.push_back(startCity);
    return path;
}

int calculateTourLength(vector<vector<int>>& graph, vector<int>& path) {
    int length = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        length += graph[path[i]][path[i+1]];
    }
    return length;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    int startCity = 0;
    vector<int> path = tspGreedy(graph, startCity);
    
    cout << "Greedy TSP Path: ";
    for (int city : path) {
        cout << city << " ";
    }
    
    int tourLength = calculateTourLength(graph, path);
    cout << "\nTour Length: " << tourLength << endl;
    
    return 0;
}
