#include <bits/stdc++.h>

using namespace std;

bool appendAndDelete(string s, string t, int k) {
    bool result = false;
    int lengthS = s.size();
    int lengthT = t.size();
    for (int i = 0; i < lengthS; i++) {
        if (s[i] != t[i]) {
            break;
        }
    }
    // i--;
    int noOfSteps = 0;

    if ((lengthS == lengthT) && ((i-1) == lengthS)) { // both are same and of same length (s == t)
        noOfSteps += (lengthS * 2);
        result = noOfSteps <= k ? true : false;
    } else if ((lengthS < lengthT) && ((i-1) == lengthS)) { // string s is in string t (s < t)
        noOfSteps += (lengthT - lengthS);
        result = noOfSteps <= k ? true : false;
    } else if () { // string t is in string s (t < s)

    } else if () { // none of them are same not even length (s != t)

    } else if ()
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int k;
    cin >> k;
    if (appendAndDelete(s, t, k) <= k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

