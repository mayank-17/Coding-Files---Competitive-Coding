#include <iostream>
#define ll long long int
using namespace std;

ll extendedEuclidsMethod(ll a, ll b, ll *x, ll *y) {
    //Base Case
    if(b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extendedEuclidsMethod(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (b/a) * y1;
    return gcd;
}

int main() {
    ll x, y;
    ll a, b;
    cin >> a >> b;
    ll gcd = extendedEuclidsMethod(a, b, &x, &y);
    cout << gcd << "\n";
    return 0;
}