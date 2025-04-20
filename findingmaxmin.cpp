#include<iostream>
#include<vector>
using namespace std;

pair<int, int> findMinMax(vector<int>& arr, int low, int high) {
    if (low == high) {
        return make_pair(arr[low], arr[high]);
    }

    if (high == low + 1) {
        if (arr[high] > arr[low]) {
            return make_pair(arr[low], arr[high]);
        } else {
            return make_pair(arr[high], arr[low]);
        }
    }

    int mid = (low + high) / 2;
    pair<int, int> leftExtreme = findMinMax(arr, low, mid);
    pair<int, int> rightExtreme = findMinMax(arr, mid + 1, high);

    int minVal = min(leftExtreme.first, rightExtreme.first);
    int maxVal = max(leftExtreme.second, rightExtreme.second);

    return make_pair(minVal, maxVal);
}

int main() {
    vector<int> arr = {3, 5, 1, 8, 2, 9, 4};
    pair<int, int> result = findMinMax(arr, 0, arr.size() - 1);

    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;

    return 0;
}
