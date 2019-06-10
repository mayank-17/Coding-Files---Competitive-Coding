#include <iostream>
#define ull unsigned long long int

using namespace std;

ull calSumOfDigits(ull n) {
    ull ans = 0;
    while(n) {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int main() {
    int t; 
    cin >> t; 
    while(t--) {
        ull n;
        cin >> n;
        ull res = n * 10;
        ull i = res;
        while(i <= res+10) {
            if(calSumOfDigits(i)%10 == 0) {
                cout << i << "\n";
                break;
            }
            i++;
        }
    }
    return 0;
}