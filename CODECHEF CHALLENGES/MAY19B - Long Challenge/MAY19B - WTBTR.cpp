/* 
    Author : Mayank Sharma
    Username: mayank_17
    DO NOT COPY!
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int *arr1 = new int[n];
        int *arr2 = new int[n];
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr1[i] = x + y;
            arr2[i] = x - y;
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        double MIN = abs(arr1[0] - arr1[1]) / 2.0;
        MIN = min(abs(arr2[0] - arr2[1])/2.0, MIN);
        for(int i = 1; i < n - 1; i++) {
            MIN = min(abs(arr1[i] - arr1[i + 1])/2.0, MIN);
            MIN = min(abs(arr2[i] - arr2[i + 1])/2.0, MIN);
            if(MIN == 0.0) {
                break;
            }
        }
        cout << fixed << setprecision(6) << MIN << endl;
    }
    return 0;
}