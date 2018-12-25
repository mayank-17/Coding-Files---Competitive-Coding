#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;
typedef long long int LLI;

void climbingLeaderboard(set<LLI> scores, LLI *S, LLI *A, int n, int m) {
    vector<LLI>::iterator up;
    vector<LLI> ranks;
    for (set<LLI>:: iterator it = scores.begin(); it != scores.end(); ++it) {
        ranks.push_back(*it);
    }
    for (int i = 0; i < m; i++) {
        up = upper_bound(ranks.begin(), ranks.end(), A[i]);
        int rank = ranks.end() - up;
        cout << rank + 1 << endl;
    }
}

int main () {
    int n, m;
    cin >> n;
    LLI *S = new LLI[n];
    set<LLI> scores;
    for (int i = 0 ; i < n; i++) {
        cin >> S[i];
        scores.insert(S[i]);
    }
    cin >> m;
    LLI *A = new LLI[m];
    for (int i = 0 ; i < m; i++) {
        cin >> A[i];
    }
    climbingLeaderboard(scores, S, A, n, m);
    delete [] S;
    delete [] A;
    return 0;
}
