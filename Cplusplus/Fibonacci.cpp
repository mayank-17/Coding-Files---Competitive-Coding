#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

long long int fib(long long int N, map<long long int, long long int> &fibTable) {
	if (N == 0 || N == 1) {
		return 1;
	}

	if (fibTable[N] > 0) {
		return fibTable[N];
	}

	fibTable[N] = fib(N - 1, fibTable) + fib(N - 2, fibTable);
	return fibTable[N];
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		long long int N;
		cin >> N;
		map<long long int, long long int> fibTable;
		for (int i = 0; i < N + 1; i++) {
			fibTable[i] = 0;
		}
		cout << fib(N, fibTable) << endl;
	}
	return 0;
}
