#include <iostream>
#define ll long long

using namespace std;

ll extendedEuclidsTheorem(ll a, ll m, ll *x, ll *y) {
    // Base Case
    if (m == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    // Recursive Case
    ll x1, y1;
    ll gcd = extendedEuclidsTheorem(m, a % m, &x1, &y1);
    *x = y1;
    *y = x1 - (a/m) * y1;

    return gcd;
}

int main() {
    ll a, m;
    cin >> a >> m;
    ll x, y;
    ll gcd = extendedEuclidsTheorem(a, m, &x, &y);
    if(gcd != 1) {
        cout << "Multiplicative Modular Inverse doesn't exits" << "\n";
    } else {
        ll res = (x % m + m) % m;
        cout << res << "\n";
    }
    return 0;
}