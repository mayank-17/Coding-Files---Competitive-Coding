#include <iostream>
using namespace std;

int QABC(int N, long int *A, long int *B) {
    
    for (long int i = 0; i < N -2; i++) {
        long int DIFF = B[i] - A[i];
        if (DIFF == 0) {
            continue;
        } else if (DIFF > 0) {
            B[i] = B[i] - DIFF;
            B[i + 1] = B[i + 1] - (DIFF * 2);
            B[i + 2] = B[i + 2] - (DIFF * 3);
        } else if (DIFF < 0) {
            break;
        }	
	}	
    long int i;
    for (i = 0; i < N; i++) {
        if (A[i] == B[i]) {
            continue;
        } else {
            break;
        }
    }
    
    if (i == N) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}

int main() {
	int testCases;
	cin >> testCases;
	for(int i = 0; i < testCases; i++) {
	    long int N;
	    cin >> N;
	    long int A[N];
	    long int B[N];
	    
	    for(int j = 0; j < N; j++) {
	        cin >> A[j];
	    }
	    
	    for(int j = 0; j < N; j++) {
	        cin >> B[j];
	    }
	    
	
	    
	    int check = QABC(N, A, B);
	    
	    if (check == 1) {
	        cout << "TAK" << endl;
	    } else {
	        cout << "NIE" << endl;
	    }
	    
	}
	return 0;
}

