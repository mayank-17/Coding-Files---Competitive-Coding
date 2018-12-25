#include <iostream>
#include <set>
using namespace std;

void printVisibleNumbers(int N, int *A) {
    int count = 0;
    set<int> S;
    
    for (int i = 0; i < N; i++) {
        S.insert(A[i]);
    }
    int result = 0;
    for (int uniqueValue : S) {
        count = 0;
        for (int j = 0; j < N; j++) {
            if (uniqueValue == A[j]) {
                count += 1;
            } 
            if (count > static_cast<int>(N/3)) {
                cout << uniqueValue << " ";
                result = 1;
                break;
            }
        }
    }
    if (result == 0) {
        cout << -1;
    }
    cout << endl;
    
}

int main() {
	int testCases;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
	    int N;
	    cin >> N;
	    int A[N];
	    for (int j = 0; j < N; j++) {
	        cin >> A[j];
	    }
	    
	    printVisibleNumbers(N, A);
	}
	return 0;
}
