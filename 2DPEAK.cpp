#include <iostream>
#include <vector>
#include<climits>
using namespace std;

// Function to find the index of the max element in a column
int findMaxIndexInColumn(const vector<vector<int>>& matrix, int col) {
    int maxIndex = 0;
    for (int i = 1; i < matrix.size(); i++) {
        if (matrix[i][col] > matrix[maxIndex][col]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Recursive function to find a peak
pair<int, int> find2DPeak(const vector<vector<int>>& matrix, int startCol, int endCol) {
    int midCol = (startCol + endCol) / 2;
    int maxRow = findMaxIndexInColumn(matrix, midCol);

    int current = matrix[maxRow][midCol];
    int left = (midCol - 1 >= 0) ? matrix[maxRow][midCol - 1] : INT_MIN;
    int right = (midCol + 1 < matrix[0].size()) ? matrix[maxRow][midCol + 1] : INT_MIN;

    // Check if current is a peak
    if (current >= left && current >= right) {
        return {maxRow, midCol};
    }
    // Move to left half
    else if (left > current) {
        return find2DPeak(matrix, startCol, midCol - 1);
    }
    // Move to right half
    else {
        return find2DPeak(matrix, midCol + 1, endCol);
    }
}

// Wrapper function
pair<int, int> findPeak2D(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {-1, -1};
    return find2DPeak(matrix, 0, matrix[0].size() - 1);
}

int main() {
    vector<vector<int>> matrix = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    pair<int, int> peak = findPeak2D(matrix);
    cout << "Peak found at index (" << peak.first << ", " << peak.second << ") with value " 
         << matrix[peak.first][peak.second] << endl;

    return 0;
}
