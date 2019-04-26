#include<iostream>
#include<string.h>
using namespace std;

//int getWays(int n, int *d, int k) {
//    if (n == 0) {
//        return 1;
//    }
//
//    if (n < 0) {
//        return 0;
//    }
//
//    if (k == 0) {
//        return 0;
//    }
//
//    int opt1 = getWays(n - d[0], d, k);
//    int opt2 = getWays(n, d + 1, k - 1);
//    return opt1 + opt2;
//}

int getWays(int n, int *d, int k, int **dp) {
    if (n == 0) {
        return 1;
    }

    if (n < 0 || k == 0) {
        return 0;
    }

    if (dp[n][k] >= 0) {
        return dp[n][k];
    }
    int opt1 = getWays(n - d[0], d, k, dp);
    int opt2 = getWays(n, d + 1, k - 1, dp);
    dp[n][k] = opt1 + opt2;
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    int *d = new int[k + 1];
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }
    int **dp = new int*[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = new int[k + 1];
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < k + 1; j++) {
            dp[i][j] = -1;
        }
    }
    cout << getWays(n, d, k, dp) << endl;
    return 0;
}
