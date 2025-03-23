#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> // Include this for max_element

using namespace std;

int count_stages(vector<vector<int>>& multistagegraph) {
    int n = multistagegraph.size();
    vector<int> stages(n, 0);

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (multistagegraph[i][j] != INT_MAX) {
                stages[i] = max(stages[i], 1 + stages[j]);
            }
        }
    }
    return *max_element(stages.begin(), stages.end()) + 1;
}

vector<int> find_min_cost_path(vector<vector<int>>& multistagegraph) {
    int n = multistagegraph.size();
    vector<int> cost(n, INT_MAX);
    vector<int> d(n, -1);
    vector<int> path;

    cost[n - 1] = 0;

    for (int j = n - 2; j >= 0; --j) {
        for (int r = j + 1; r < n; ++r) {
            if (multistagegraph[j][r] != INT_MAX && multistagegraph[j][r] + cost[r] < cost[j]) {
                cost[j] = multistagegraph[j][r] + cost[r];
                d[j] = r;
            }
        }
    }

    int node = 0;
    path.push_back(node + 1);
    while (d[node] != -1) {
        node = d[node];
        path.push_back(node + 1);
    }

    return path;
}

int main() {
    vector<vector<int>> multistagegraph = {
        {0, 3, 4, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, 6, 5, INT_MAX},
        {INT_MAX, INT_MAX, 0, 7, 9, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 11},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 8},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
    };

    int stages = count_stages(multistagegraph);
    cout << "Number of stages: " << stages << endl;

    vector<int> minCostPath = find_min_cost_path(multistagegraph);
    cout << "Minimum-cost path: ";
    for (int node : minCostPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

