#include<iostream>
#include<algorithm>
using namespace std;

struct item {
    int value;
    int weight;
    double ratio;
};

bool cmp(item a, item b) {
    return a.ratio > b.ratio;
}

void knapsack01(int W, item arr[], int n) {
    sort(arr, arr + n, cmp);

    int currentWeight = 0;
    int totalValue = 0;
    bool* selected = new bool[n]();

    for(int i = 0; i < n; i++) {
        if(currentWeight + arr[i].weight <= W) {
            selected[i] = true;
            currentWeight += arr[i].weight;
            totalValue += arr[i].value;
        }
    }

    cout << "\nSelected Items:\n";
    cout << "Value\tWeight\n";
    for(int i = 0; i < n; i++) {
        if(selected[i]) {
            cout << arr[i].value << "\t" << arr[i].weight << "\n";
        }
    }

    cout << "\nTotal weight: " << currentWeight << endl;
    cout << "Total value: " << totalValue << endl;

    delete[] selected;
}
// kjhj

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    item* Item = new item[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter value for item " << i+1 << ": ";
        cin >> Item[i].value;
        cout << "Enter weight for item " << i+1 << ": ";
        cin >> Item[i].weight;
        Item[i].ratio = (double)Item[i].value / Item[i].weight;
    }

    knapsack01(W, Item, n);

    delete[] Item;
    return 0;
}