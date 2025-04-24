#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n = 5; // means 4 matrices: A1: 40x20, A2: 20x30, A3: 30x10, A4: 10x30
    int p[] = {40, 20, 30, 10, 30}; // dimensions of matrices

    int m[n][n]; // Minimum cost table
    int s[n][n]; // k values (for parenthesization)

    // Initialize diagonals to 0
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // l is the chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications is: " << m[1][n-1] << endl;

    return 0;
}
