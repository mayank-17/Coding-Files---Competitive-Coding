#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, t, m, n, a, b;
    cin >> s >> t;
    cin >> a >> b;
    cin >> m >> n;
    int aCount = 1;
    for (int i = 0; i < m; i++) {
        int appleDistance;
        cin >> appleDistance;
        if (appleDistance >= 0) {
            int d = appleDistance + a;
//            cout << d << "apple" << endl;
            if (d >= s && d <= t) {
                aCount += 1;
            }
        }
    }
    int oCount = 1;
    for (int i = 0; i < n; i++) {
        int orangeDistance;
        cin >> orangeDistance;
        if (orangeDistance <= 0) {
            int d = orangeDistance + b;
//            cout << d << "orange" << endl;
            if (d >= s && d <= t) {
                oCount += 1;
            }
        }
    }
    cout << aCount << endl;
    cout << oCount << endl;
    return 0;
}
