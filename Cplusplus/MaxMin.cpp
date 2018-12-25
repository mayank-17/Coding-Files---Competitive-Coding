#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int maxMin(int k, int *arr, int n) {

    sort(arr, arr + n);

    int unfairness = arr[n - 1];

    int temp = 0;

    for (int i = 0; i < n + 1 - k; i++) {
        temp = arr[i + k - 1] - arr[i];

        if (temp <= unfairness) {
            unfairness = temp;
        }
    }

    return unfairness;
}

int main() {
    int n, k;

    cin >> n;
    cin >> k;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxMin(k, arr, n);

    return 0;
}
