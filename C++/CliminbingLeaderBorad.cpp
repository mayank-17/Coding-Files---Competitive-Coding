#include <bits/stdc++.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int LLI;

void climbingLeaderboard (LLI n, set<LLI> s, LLI m, LLI *a) {
    set<LLI>::iterator up;
    for (LLI i = 0; i < m; i++) {
        up = upper_bound(s.begin(), s.end(), a[i]);
        cout << (up - s.begin());
    }
}

int main () {
    LLI n;
    cin >> n;
    set<LLI> scores;
    for (LLI i = 0; i < n; i++) {
        LLI X; cin >> X;
        scores.insert(X);
    }
    LLI m;
    cin >> m;
    LLI *alice = new LLI[m];
    for (LLI j = 0; j < m; j++) {
        cin >> alice[j];
    }
    climbingLeaderboard(n, scores, m, alice);
    return 0;
}
