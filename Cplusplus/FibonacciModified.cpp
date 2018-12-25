#include <bits/stdc++.h>

using namespace std;

int fibonacciModified(int t1, int t2, int n) {
    int arr[n+1];

    arr[1] = t1;
    arr[2] = t2;

    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i-2] + (arr[i-1] * arr[i-1]);
    }
    return arr[n];
}

int main() {
    int t1, t2, n;

    cin >> t1 >> t2 >> n;

    cout << fibonacciModified(t1, t2, n) << endl;

    return 0;
}

