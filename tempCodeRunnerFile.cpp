
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