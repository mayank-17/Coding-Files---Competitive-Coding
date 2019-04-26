#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long long int solveEgoStone (long long int N) {
	return N * (pow(N, 2) + 1) / 2;
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		long long int result = solveEgoStone(N);
		cout << result << endl;
	}
}
