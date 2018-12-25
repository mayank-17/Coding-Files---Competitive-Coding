#include <bits/stdc++.h>
using namespace std;

int tdp[100][100];

int MatrixChainBottomUp(int m[], int n) {

    // Make diagonals zero
    for (int i = 1; i < n; i++) {
        tdp[i][i] = 0;
    }

    for (int L = 2; L < n; L++) {
        for (int i = 1; i <= n - L; i++) {
            int j = i + L - 1;
            tdp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                tdp[i][j] = min(tdp[i][j], tdp[i][k] + tdp[k+1][j] + (m[i-1]*m[k]*m[j]));
            }
        }
    }
    return tdp[1][n-1];
}

int MatrixChainTopDown(int m[], int i, int j) {
    // Base Case
    if (i == j) {
        return 0;
    }

    // Overlapping Subproblems
    if (tdp[i][j] != -1) {
        return tdp[i][j];
    }
    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        int temp = MatrixChainTopDown(m, i, k) + MatrixChainTopDown(m, k + 1, j) + m[i-1]*m[k]*m[j];
        ans = min(ans, temp);
    }
    tdp[i][j] = ans;
    return ans;
}

int MatrixChainRecursive(int m[], int i, int j) {
    // Base Case
    if (i == j) {
        return 0;
    }

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        int temp = MatrixChainRecursive(m, i, k) + MatrixChainRecursive(m, k + 1, j) + m[i-1]*m[k]*m[j];
        ans = min(ans, temp);
    }
    return ans;
}

int main() {
    int matrices[] = {1, 2, 3, 4};
    int n = sizeof(matrices) / sizeof(matrices[0]);
//    memset(tdp, -1, sizeof(tdp));

//    cout << MatrixChainRecursive(matrices, 1, n - 1) << endl;
//    cout << MatrixChainTopDown(matrices, 1, n - 1) << endl;
    cout << MatrixChainBottomUp(matrices, n) << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << tdp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
