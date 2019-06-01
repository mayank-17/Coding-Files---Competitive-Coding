#include <iostream>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll stringToInt(string s, ll m) {
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans = (ans * 10) % m + s[i] - '0';
        ans %= m;
    }
    return ans;
}

ll fastExponentiation(ll x, ll y, ll m) {
    if(y == 0) {
        return 1;
    }
    if(y == 1) {
        return x;
    }
    ll res = 1;
    while(y) {
        if(y & 1){
            res = (res*x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

int main(){
    ll t;
    cin >> t;
    string a, b;
    while(t--) {
        cin >> a >> b;

        // String to Integer
        ll x = stringToInt(a, MOD);
        ll y = stringToInt(b, MOD - 1);

        // Power of (x, y)
        cout << fastExponentiation(x, y, MOD) << "\n";
        
    }
    return 0;
} 