#include<iostream>
using namespace std;

int amountOfMoney(int b, int *k, int *u, int n, int m) {
    int maxSoFar = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (k[i] < b) {
            for (int j = m - 1; j >= 0; j--) {
                if (k[i] + u[j] <= b && maxSoFar < k[i] + u[j]) {
                    maxSoFar = k[i] + u[j];
                }
            }
        }
    }
    return maxSoFar;
}

int main() {
    int budget, n, m;
    cin >> budget >> n >> m;
    int *keyboards = new int[n];
    int *usb = new int[m];
    for (int i = 0; i < n; i++) {
        cin >> keyboards[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> usb[i];
    }
    cout << amountOfMoney(budget, keyboards, usb, n, m) << endl;
}
