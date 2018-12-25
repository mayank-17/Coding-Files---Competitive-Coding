#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define ll long long

ll fastModExp(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

int main () {
    ll a = 12817, b = 12312378, m = 1000000000;
//    cin >> a >> b >> m;
    cout << fastModExp(a, b, m) << endl;
    cout << pow(a, b) << endl;
    return 0;
}
