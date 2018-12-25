#include <bits/stdc++.h>
using namespace std;

int reverseOfNumber(int num) {
	int sum = 0;
	int rem = 0;
	while (num != 0) {
		rem = num % 10;
		sum = (sum * 10) + rem;
		num /= 10;
	}
	return sum;
}

int main () {
	int number;
	cin >> number;
	
	int result = reverseOfNumber(number);
	cout << result << endl;
}
