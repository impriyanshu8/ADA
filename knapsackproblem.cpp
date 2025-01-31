#include <iostream>
#include <algorithm>
using namespace std;

struct item {
    int value;
    int weight;
    double ratio;
};

bool cmp(item a, item b) {
    return a.ratio > b.ratio;
}

item* fractionalKnapsack(int W, item arr[], int n, int &selectedCount) {
    sort(arr, arr + n, cmp);

    double totalValue = 0.0;
    item* selectedItems = new item[n];
    selectedCount = 0;

    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {  
            W -= arr[i].weight;
            totalValue += arr[i].value;
            selectedItems[selectedCount++] = arr[i];
        } else {  
            item fraction;
            fraction.value = arr[i].value * ((double)W / arr[i].weight);
            fraction.weight = W;
            fraction.ratio = arr[i].ratio;
            totalValue += fraction.value;
            selectedItems[selectedCount++] = fraction;
            break;
        }
    }

    cout << "\nSelected Items in Knapsack:" << endl;
    for (int i = 0; i < selectedCount; i++) {
        cout << "Value: " << selectedItems[i].value << ", Weight: " << selectedItems[i].weight 
             << ", Ratio: " << selectedItems[i].ratio << endl;
    }

    cout << "\nMaximum profit in Knapsack = " << totalValue << endl;
    return selectedItems;
}

int main() {
    int n, cap;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> cap;

    item* Item = new item[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the profit of item " << i + 1 << ": ";
        cin >> Item[i].value;
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> Item[i].weight;
        Item[i].ratio = (double)Item[i].value / Item[i].weight;
    }

    int selectedCount;
    item* selectedItems = fractionalKnapsack(cap, Item, n, selectedCount);

    delete[] Item;
    delete[] selectedItems;

    return 0;
}
