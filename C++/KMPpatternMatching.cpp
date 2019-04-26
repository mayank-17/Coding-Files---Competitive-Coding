#include <bits/stdc++.h>

using namespace std;

int *computeLPS(string pattern) {
    int *arr = new int[pattern.length()];
    arr[0] = 0;
    int j = 0, i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[j]) {
            j++;
            arr[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = arr[j - 1];
            } else {
                arr[i] = j;
                i++;
            }
        }
    }
    return arr;
}

bool KMPpatternSearching(string text, string pattern) {
    int *lps = computeLPS(pattern);
    int N = text.length();
    int M = pattern.length();
    int i = 0, j = 0;
    bool found = false;
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == M) {
            found = true;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return found;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        string text;
        string pattern;
        cin >> text >> pattern;
        string result = KMPpatternSearching(text, pattern) ? "Pattern Found!" : "Pattern not Found!";
        cout << result << endl;
    }
    return 0;
}
