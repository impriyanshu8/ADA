// #include <iostream>
// #include <vector>
// #include <climits>
// #include <algorithm> // Include this for max_element

// using namespace std;

// int count_stages(vector<vector<int>>& multistagegraph) {
//     int n = multistagegraph.size();
//     vector<int> stages(n, 0);

//     for (int i = n - 2; i >= 0; --i) {
//         for (int j = i + 1; j < n; ++j) {
//             if (multistagegraph[i][j] != INT_MAX) {
//                 stages[i] = max(stages[i], 1 + stages[j]);
//             }
//         }
//     }
//     return *max_element(stages.begin(), stages.end()) + 1;
// }

// vector<int> find_min_cost_path(vector<vector<int>>& multistagegraph) {
//     int n = multistagegraph.size();
//     vector<int> cost(n, INT_MAX);
//     vector<int> d(n, -1);
//     vector<int> path;

//     cost[n - 1] = 0;

//     for (int j = n - 2; j >= 0; --j) {
//         for (int r = j + 1; r < n; ++r) {
//             if (multistagegraph[j][r] != INT_MAX && multistagegraph[j][r] + cost[r] < cost[j]) {
//                 cost[j] = multistagegraph[j][r] + cost[r];
//                 d[j] = r;
//             }
//         }
//     }

//     int node = 0;
//     path.push_back(node + 1);
//     while (d[node] != -1) {
//         node = d[node];
//         path.push_back(node + 1);
//     }

//     return path;
// }

// int main() {
//     vector<vector<int>> multistagegraph = {
//         {0, 3, 4, INT_MAX, INT_MAX, INT_MAX},
//         {INT_MAX, 0, INT_MAX, 6, 5, INT_MAX},
//         {INT_MAX, INT_MAX, 0, 7, 9, INT_MAX},
//         {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 11},
//         {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 8},
//         {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
//     };

//     int stages = count_stages(multistagegraph);
//     cout << "Number of stages: " << stages << endl;

//     vector<int> minCostPath = find_min_cost_path(multistagegraph);
//     cout << "Minimum-cost path: ";
//     for (int node : minCostPath) {
//         cout << node << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int stages = 4;
    int n = 8;
    int cost[9] = {0}, d[9] = {0}, path[9] = {0};

    // Cost matrix C[i][j]
    int C[9][9] = {
        {0}, // index 0 not used
        {0,0,1,2,5,0,0,0,0},
        {0,0,0,0,0,4,11,0,0},
        {0,0,0,0,0,9,5,16,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,13,0},
        {0,0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,0,0,5},
        {0,0,0,0,0,0,0,0,0}
    };

    // Step 1: Initialize cost of destination to 0
    cost[n] = 0;

    // Step 2: DP from i = n-1 down to 1
    for (int i = n - 1; i >= 1; i--) {
        int min = INT_MAX;

        for (int k = i + 1; k <= n; k++) {
            if (C[i][k] != 0 && C[i][k] + cost[k] < min) {
                min = C[i][k] + cost[k];
                d[i] = k;
            }
        }

        cost[i] = min;
    }

    // Step 3: Construct path
    path[1] = 1;
    path[stages] = n;

    for (int i = 2; i < stages; i++) {
        path[i] = d[path[i - 1]];
    }

    // Output cost
    cout << "Minimum cost from source to destination: " << cost[1] << endl;

    // Output path
    cout << "Shortest path: ";
    for (int i = 1; i <= stages; i++) {
        cout << path[i];
        if (i != stages) cout << " -> ";
    }
    cout << endl;

    return 0;
}
//done