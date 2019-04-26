#include <bits/stdc++.h>
using namespace std;

long long factorial(long long num) {
	long long fact = 1;
	for (long long i = num; i > 0; i--) {
		fact *= i;
	}
	return fact;
}

int main() {
	long long number;
	cin >> number;
	long long result = factorial(number);
	cout << result << endl;
	return 0;
}
