#include<iostream>
using namespace std;

int kadaneAlgorithm(int *A, int N) {
    int currentMaximum = A[0];
    int maximumSoFar = A[0];
    for (int i = 1; i < N; i++) {
        currentMaximum = max(A[i], currentMaximum + A[i]);
        maximumSoFar = max(maximumSoFar, currentMaximum);
    }
    return maximumSoFar;
}

int main()
 {
	int testCases;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
	    int N;
	    cin >> N;
	    int arr[N];
	    for (int j = 0; j < N; j++) {
	        cin >> arr[j];
	    }
	    int result = kadaneAlgorithm(arr, N);
	    cout << result << endl;
	}
	return 0;
}
