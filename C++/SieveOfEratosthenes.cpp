#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int N) {
	bool primes[N+1];
	memset(primes, true, sizeof(primes));
	
	for (int p = 2; p * p <= N; p++) {
		if (primes[p] == true) {
			for (int i = p * 2; i <= N; i += p) {
				primes[i] = false;
			}
		}
	}
	
	for (int i = 2; i < N+1; i++) {
		if (primes[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
}

int main () {
	int testCases;
	cin >> testCases;
	
	for (int i = 0; i < testCases; i++) {
		int number;
		cin >> number;
		sieveOfEratosthenes(number);
	}
	return 0;
}
