#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll calculateNoOfDays(ll N, ll *A) {
	ll peopleKnow = 0;
	ll day = 0;
	ll lastIndex = 0;
	
	peopleKnow = A[0];
	ll sum = 0;
	while(lastIndex < N-1) {
		ll temp = lastIndex;
		lastIndex += peopleKnow;
		
		for (ll i = temp + 1; i < lastIndex + 1; i++) {
			sum += A[i];
		}
		peopleKnow += sum;
		day += 1;
	}
	return day;
}
	
int main() {
    int testCases;
	cin >> testCases;
	
	for (int i = 0; i < testCases; i++) {
		ll N;
		cin >> N;
		ll A[N];
		for (ll j = 0; j < N; j++) {
			cin >> A[j];
		}
		
		ll days = calculateNoOfDays(N, A);
		
		cout << days << endl;
	}
	return 0;
}

