#include <iostream>
#include <vector>
using namespace std;

void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        cout << "Magic Square requires an odd number.\n";
        return;
    }

    vector<vector<int>> magicSquare(n, vector<int>(n, 0));
    int i = 0, j = n / 2;  // Start position: middle of first row

    for (int k = 1; k <= n * n; ++k) {
        magicSquare[i][j] = k;

        // Calculate next position (up-right)
        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;

        // If next cell is already occupied, move down 
        if (magicSquare[new_i][new_j] != 0) {
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }

    // Print the magic square
    cout << "Magic Square of size " << n << ":\n";
    for (const auto &row : magicSquare) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter an odd number for Magic Square: ";
    cin >> n;
    generateMagicSquare(n);
    return 0;
}