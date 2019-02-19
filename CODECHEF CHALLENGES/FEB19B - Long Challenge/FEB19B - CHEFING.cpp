#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        unordered_map<char, int> M;
        for(int i = 0; i < n; i++) {
            char s[200];
            scanf("%s", &s);
            unordered_set<char> S;
            for(int i = 0; i < strlen(s); i++) {
                S.insert(s[i]);
            }
            for(auto s : S) {
                M[s]++;
            }
        }
        int count = 0;
        for(auto m : M) {
            if(m.second == n) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}