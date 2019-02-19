#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    scanf("%d", &t);
    while(t--) {
        char s[1000000];
        scanf("%s", &s);
        int charCount[26] = {0};
        int l = strlen(s);
        for(int i = 0; i < l; i++) {
            charCount[s[i] - 'A']++;
        }
        sort(charCount, charCount + 26, greater<int>());
        int toCheck = min(l, 26);
        int res, ans = INT_MAX;
        for(int i = 1; i <= toCheck; i++) {
            if(l % i == 0) {
                res = 0;
                int f = l / i;
                int e = 0;
                for(int j = 0; j < i; j++) {
                    if(charCount[j] + e < f) {
                        e = 0;
                        res += f - charCount[j] - e;
                    } else {
                        e -= f - charCount[j];
                        if(e < 0) {
                            res -= e;
                        }
                        e = 0;
                    }
                }
                ans = min(ans, res);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}