#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

long long int minimumNoOfSteps(int *A, int N, int K) {
	long long int steps = 0LL;
	if ((A[0] - 0) > K) {
		if ((A[0] - 0) % K != 0) {
			steps += (A[0] - 0) / K;	
		} else {
			steps += ((A[0] - 0) / K) - 1;
		}
		
	}
//	cout << A[0] << "-" << 0 << endl;
//	cout << (A[0] - 0) / K << endl;
	for (int i = 1; i < N; i++) {
		int temp = A[i] - A[i-1];
		if (temp <= K) {
			continue;
		}
		else {
			if(temp % K != 0) {
				steps += temp / K;
			} else {
				steps += (temp / K) - 1;
			}
		}	
//		cout << A[i] << "-" << A[i-1] << endl;
//		cout << temp / K << endl;
	}
	return steps;
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		int A[N];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		long long int result = minimumNoOfSteps(A, N, K);
		cout << result << endl;
	}
	return 0;
}
