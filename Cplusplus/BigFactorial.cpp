#include <iostream>
using namespace std;
void multiply(int *arr, int &n, int num) {
    // array 1 2 3 0 0 0 0 by 4
    int carry = 0;

    for(int i = 0; i < n; i++) {
        int prod = arr[i] * num + carry;
        arr[i] = prod % 10;
        carry = prod / 10;
    }

    // left out carry
    while(carry) {
        arr[n] = carry % 10;
        carry /= 10;
        n++;
    }
}

void bigFactorial(int number) {
    // Assuming that ans contains at max 1000 digits, all positions are 0 initially
    int *arr = new int[1000]{0};
    arr[0] = 1;
    int n = 1; // denotes the index of the array, before which we have stored some digits
    for(int i = 2; i < number + 1; i++) {
        multiply(arr, n, i);
    }
    for(int i = n - 1; i >= 0; i--) {
        cout << arr[i];
    }
    cout << endl;
}

int main() {
    int X;
    cin >> X;
    bigFactorial(X);
    return 0;
}
