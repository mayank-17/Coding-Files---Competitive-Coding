#include <iostream>
#include <cmath>
using namespace std;

void byteToBit(int N) {
    long long int count = 0;
    N -= 1;
    count = (long long int) N / 26;
    long long int rem = N % 26;
    if (rem < 2) {
        cout << (long long int) pow(2, count) << " " << 0 << " " << 0 << endl;
    } else if ((rem > 1) && (rem < 10)) {
        cout << 0 << " " << (long long int) pow(2, count) << " " << 0 << endl;
    } else if ((rem > 9) && (rem < 27)) {
        cout << 0 << " " << 0 << " " << (long long int) pow(2, count) << endl;
    }
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
	    int N;
	    cin >> N;
	    byteToBit(N);
	}
	return 0;
}

