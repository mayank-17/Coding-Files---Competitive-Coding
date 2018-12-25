#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void fastscan(int &number)
{
	bool negative = false;
	register int c;

	number = 0;
	c = getchar();
	if (c=='-')
	{
		negative = true;
		c = getchar();
	}
	for (; (c>47 && c<58); c=getchar()) {
	    number = number *10 + c - 48;
	}
	if (negative) {
	    number *= -1;
	}
}

int happiness(int *arr, int N) {
//    int *A = new int[N];
    vector<int> A;
//    set<int> S;
    for (int i = 0; i < N; i++) {
//        cout << arr[arr[i] - 1] << " ";
        A.push_back(arr[arr[i] - 1]);
//        S.insert(arr[arr[i] - 1]);
    }
    sort(A.begin(), A.begin() + N);

    for (int i = 0; )

//    for (int i = 0; i < N; i++) {
//        cout << A[i] << " ";
//    }
//    cout << endl;

//    int flag = 0;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (i != j) {
//                if (arr[i] != arr[j]) {
//                    if (arr[arr[i] - 1] == arr[arr[j] - 1]) {
//                        flag = 1;
//                        break;
//                    }
//                }
//            }
//        }
//        if (flag == 1) {
//            break;
//        }
//    }
//    if (flag == 1) {
//        return 1;
//    } else {
//        return 0;
//    }
    return 0;
}

int main () {
    int T;
    fastscan(T);
    while (T--) {
        int N;
        // cin >> N;
        fastscan(N);
        int *arr = new int[N];
        for (int i = 0; i < N; i++) {
            // cin >> arr[i];
            int x;
            fastscan(x);
            arr[i] = x;
        }
        int result = happiness(arr, N);
        if (result == 1) {
            cout << "Truly Happy" << endl;
        } else {
            cout << "Poor Chef" << endl;
        }
    }
    return 0;
}
