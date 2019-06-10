#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int days;
        cin >> days;
        string attend;
        cin >> attend;
        int countProxy = 0;
        int totalPresent = count(attend.begin(), attend.end(), 'P');
        bool flag = false;
        int bar = ceil(days * 0.75);
        if(totalPresent >= bar) {
            cout << "0\n";
        } else if(days <= 4) {
            cout << "-1\n";
        } else {
            for(int i = 2; i < days-2; ++i) {
                if(attend[i] == 'A' &&(attend[i-2] == 'P' || attend[i-1] == 'P') && (attend[i+2] == 'P' || attend[i+1] == 'P')) {
                    countProxy++;
                    if(totalPresent + countProxy >= bar) {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) cout << countProxy << "\n";
            if(!flag) cout << "-1\n";
        }
    }
    return 0;
}