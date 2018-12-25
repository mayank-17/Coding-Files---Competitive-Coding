#include <iostream>
using namespace std;

void possibleGames(int *arr, int k) {
    for(int a = 0; a < k - 5; a++) {
        for(int b = a + 1; b < k - 4; b++) {
            for(int c = b + 1; c < k - 3; c++) {
                for(int d = c + 1; d < k - 2; d++) {
                    for(int e = d + 1; e < k - 1; e++) {
                        for(int f = e + 1; f < k; f++) {
                            cout << arr[a] << " " << arr[b] << " " << arr[c] << " " << arr[d] << " " << arr[e] << " " << arr[f] << endl;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int k;
    cin >> k;
    int *arr = new int[k];
    for(int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    possibleGames(arr, k);
    return 0;
}
