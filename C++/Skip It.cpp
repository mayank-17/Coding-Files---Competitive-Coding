#include <bits/stdc++.h>
using namespace std;

long long int calculateCarrots(int *A, int N, int Q) {
	long long int sum = 0;
	Q = Q + 1;
	for (int i = 0; i < N; i += Q) {
		sum += A[i];
	}
	return sum;
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int N, Q;
		cin >> N >> Q;
		int A[N];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < Q; i++) {
			int query;
			cin >> query;
			long long int result = calculateCarrots(A, N, query);
			cout << result << endl;
		}
	}
}
