#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll arr[n];
		ll res = 0;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			res += arr[n] - 1;
		}
		cout << res + 1 << "\n";
	}
	return 0;
}