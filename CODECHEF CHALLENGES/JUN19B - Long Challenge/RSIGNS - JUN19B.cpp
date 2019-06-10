#include <iostream>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll fastExponentiation(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res = (res % MOD * a % MOD) % MOD;
        }
        b >>= 1;
        a = (a%MOD * a%MOD) % MOD;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll k;
        cin >> k;
        cout << (fastExponentiation(2, (k-1)) * 10) % MOD << "\n";
    }
    return 0;
}