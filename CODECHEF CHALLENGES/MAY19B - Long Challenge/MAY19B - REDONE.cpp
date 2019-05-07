/* 
    Author : Mayank Sharma
    Username: mayank_17
    DO NOT COPY!
*/

#include <iostream>
#define MOD 1000000007
using namespace std;

long long arr[1000001];

void preCompute() {
    arr[1] = 1;
    for(int i = 2; i < 1000001; ++i) {
        long long a = (i) % MOD;
        long long b = arr[i - 1] % MOD;
        arr[i] = ((a + b) % MOD + (a * b) % MOD) % MOD;
    }
}

int main() {
    preCompute();
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        cout << arr[n] << "\n";
    }
    return 0;
}