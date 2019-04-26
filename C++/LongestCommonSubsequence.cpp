#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return (a>b) ? a:b;
}

void longestCommonSubsequence(int *arr1, int *arr2, int n, int m) {
    int DP[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <=m; j++) {
            if (i == 0 || j == 0) {
                DP[i][j] = 0;
            } else if (arr1[i - 1] == arr2[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    // For printing LCS

    int index = DP[n][m];
    int size = index - 1;
    int output[index];

    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (arr1[i - 1] == arr2[j - 1]) {
            output[size] = arr1[i - 1];
            i--;
            j--;
            size--;
        } else if (DP[i - 1][j] > DP[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    for (int i = 0; i < index; i++) {
        cout << output[i] << " ";
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    int *arr1 = new int[n];
    int *arr2 = new int[m];

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    longestCommonSubsequence(arr1, arr2, n, m);

    delete [] arr1;
    delete [] arr2;
    return 0;
}
