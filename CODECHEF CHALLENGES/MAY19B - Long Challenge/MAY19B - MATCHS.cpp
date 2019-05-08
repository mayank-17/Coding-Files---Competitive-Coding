/* 
    Author : Mayank Sharma
    Username: mayank_17
    DO NOT COPY!
*/

#include <iostream>
#define ll long long
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        if(n == m) {
            cout << "Ari\n";
            continue;
        }
        if(n < m) {
            swap(n, m);
        }
        ll ans = n / m;
        if(ans > 1) {
            cout << "Ari\n";
        } else {
            bool chance = 1;
            while(n > 0 && m > 0) {
                n -= (ans * m);
                if(n < m) {
                    swap(n, m);
                }
                ans = n / m;
                if(ans > 1 && chance) {
                    cout << "Rich\n";
                    break;
                } else if(ans > 1 && !chance) {
                    cout << "Ari\n";
                    break;
                } else {
                    chance = !chance;
                    continue;
                }
            }
        }
    }
    return 0;
}