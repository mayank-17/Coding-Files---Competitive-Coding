#include<iostream>
using namespace std;
typedef long long ll;

ll minStepsBottomUp(ll n) {
    ll *arr = new ll[n + 1];
    arr[1] = 0;
    for (ll i = 2; i < n + 1; i++) {
        ll ans = 1 + arr[i - 1];
        if (i % 2 == 0) {
            ans = min(ans, 1 + arr[i / 2]);
        }
        if (i % 3 == 0) {
            ans = min(ans, 1 + arr[i / 3]);
        }
        arr[i] = ans;
    }
    ll output = arr[n];
    delete [] arr;
    return output;
}

int minStepsTopDown(int n, int *arr) {
    if (n == 1) {
        return 0;
    }

    if (arr[n] > 0) {
        return arr[n];
    }
    int ans;
    if (n % 2 == 0) {
        ans = min(ans, 1 + minStepsTopDown(n / 2, arr));
    }

    if (n % 3 == 0) {
        ans = min(ans, 1 + minStepsTopDown(n / 3, arr));
    }
    arr[n] = ans;
    return ans;
}

int minStepsRecursion(int n) {
    if (n == 1) {
        return 0;
    }

    int ans = 1 + minStepsRecursion(n - 1);

    if (n % 2 == 0) {
        ans = min(ans, 1 + minStepsRecursion(n / 2));
    }

    if (n % 3 == 0) {
        ans = min(ans, 1 + minStepsRecursion(n / 3));
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    int X = T;
    while (T--) {
        ll n;
        cin >> n;
        cout << "Case " << X - T << ": " << minStepsBottomUp(n) << endl;
    }
    return 0;
}
