#include <bits/stdc++.h>

using namespace std;

int countDigit(int n) {
    return floor(log10(n) + 1);
}

int findDigits(int n) {
    int N = n;
    int digits = countDigit(n);
    int *arr = new int[digits];
    int i = 0;
    while(n != 0) {
        int rem = n % 10;
        n /= 10;
        arr[i++] = rem;
    }
    int count = 0;
    for (i = 0; i < digits; i++) {
        if ((arr[i] != 0) && (N % arr[i] == 0)) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        cout << findDigits(N) << endl;
    }
    return 0;
}
