#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

void missingNumbers(vector<int> &arr, vector<int> &brr) {
    map<int, int> B;
    for (int i = 0; i < brr.size(); i++) {
        int count = 0;
        for (int j = 0; j < brr.size(); j++) {
            if (brr[i] == brr[j]) {
                count += 1;
            }
        }
        B[brr[i]] = count;
    }
	map<int, int> A;
	for (int i = 0; i < arr.size(); i++) {
		int count = 0;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[i] == arr[j]) {
				count += 1;
			}
		}
		A[arr[i]] = count;
	}
	
    for (map<int, int>::iterator itB = B.begin(); itB != B.end(); itB++) {
    	int key = itB->first;
    	if (A[key] != B[key]) {
    		cout << key << " ";
		}     
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int X; cin >> X;
        A.push_back(X);
    }
    int M;
    cin >> M;
    vector<int> B;
    for (int i = 0; i < M; i++) {
        int X; cin >> X;
        B.push_back(X);
    }
    missingNumbers(A, B);
    return 0;
}

