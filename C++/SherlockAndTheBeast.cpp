#include <bits/stdc++.h>

using namespace std;

void decentNumber(int n) {
    int temp = n;
    if(n <= 0) {
        cout << "-1" << endl;
    } else {
        if(n % 3 == 0) {
            cout << string(n, '5') << endl;
        }
        while(n % 3 != 0) {
            n -= 5;
            if(n < 0) {
                cout << "-1" << endl;
                break;
            } else {
                if(n % 3 == 0) {
                    cout << string(n, '5') << string((temp - n), '3') << endl;
                }
            }
        }
    }
}

int main() {
    int testCase;

    cin >> testCase;

    while (testCase--) {
        int num;

        cin >> num;

        decentNumber(num);
    }
    return 0;
}

