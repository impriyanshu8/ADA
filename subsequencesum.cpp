#include <iostream>
#include <vector>
using namespace std;

void printsubsequence(vector<int> &arr, vector<int> &output, int target, int index, int sum) {
    int n = arr.size();
    if (index >= n) {
        if (sum == target) {
            for (int i = 0; i < output.size(); i++) {
                cout << output[i] << " ";
            }
            cout << endl; 
        }
        return;
    }

    // Include the current element
    output.push_back(arr[index]);
    printsubsequence(arr, output, target, index + 1, sum + arr[index]);
    output.pop_back();

    // Exclude the current element
    printsubsequence(arr, output, target, index + 1, sum);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> output;
    int target = 6;
    printsubsequence(arr, output, target, 0, 0); 
    return 0;
}