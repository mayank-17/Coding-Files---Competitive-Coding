#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

float typing(map<string, int> typingTable, vector<string> S, int N) {
	char LeftHand[2] = {'d', 'f'};
	char RightHand[2] = {'j', 'k'};
	float time = 0;
	float totalTime = 0;
	int L = 0;
	int R = 0;
	for (int i = 0; i < N; i++) {
		if (typingTable[S[i]] == 0) {
			for (int j = 0; j < S[i].length(); j++) {
				if (j == 0) {
					if (S[i][j] == LeftHand[0] || S[i][j] == LeftHand[1]) {
						time += 0.2;
						L += 1;
					}
					if (S[i][j] == RightHand[0] || S[i][j] == RightHand[1]) {
						time += 0.2;
						R += 1;
					}
				} else {
					if ((S[i][j] == LeftHand[0] || S[i][j] == LeftHand[1]) && L == 1) {
						time += 0.4;
					} else if ((S[i][j] == RightHand[0] || S[i][j] == RightHand[1]) && R == 1) {
						time += 0.4;
					} else if ((S[i][j] == LeftHand[0] || S[i][j] == LeftHand[1]) && R == 1) {
						time += 0.2;
						R = 0;
						L = 1;
					} else if ((S[i][j] == RightHand[0] || S[i][j] == RightHand[1]) && L == 1) {
						time += 0.2;
						L = 0;
						R = 1;
					}
				}
//				cout << time * 10 << " " << j << endl;
			}
			typingTable[S[i]] = time * 10;
			totalTime += time * 10;
			time = 0;
		} else {
			totalTime += typingTable[S[i]] / 2;
		}
		L = 0; R = 0;
	}
	typingTable.clear();
	return totalTime;
}

int main () {
	int testCase;
	cin >> testCase;
	int N;
	map<string, int> myMap;
	vector <string> S;
	string str;
	float result;
	for (int t = 0; t < testCase; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> str;
			myMap[str] = 0;
			S.push_back(str);
		}
		result = typing(myMap, S, N);
		cout << result << endl;
		myMap.clear();
		S.clear();
	}
	return 0;
}
