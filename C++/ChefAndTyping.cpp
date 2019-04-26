#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

float calculateTime(string str) {
	char previous = str[0];
	float time = 0.2;
	for (int i = 1; i < str.length(); i++) {
		if ((previous == 'd' || previous == 'f') && (str[i] == 'd' || str[i] == 'f')) {
			time += 0.4;
		} else if ((previous == 'd' || previous == 'f') && (str[i] == 'j' || str[i] == 'k')) {
			time += 0.2;
		} else if ((previous == 'j' || previous == 'k') && (str[i] == 'j' || str[i] == 'k')) {
			time += 0.4;
		} else if ((previous == 'j' || previous == 'k') && (str[i] == 'd' || str[i] == 'f')) {
			time += 0.2;
		}
		previous = str[i];
	}
	return time;
}

float typing (vector<string> S, int N) {
	float totalTime = 0;
	set<string> typingTable;
	for (int i = 0; i < S.size(); i++) {
		if (typingTable.find(S[i]) == typingTable.end()) {
			typingTable.insert(S[i]);
			totalTime += calculateTime(S[i]);
		} else {
			totalTime += calculateTime(S[i]) / 2;
		}
	}
	typingTable.clear();
	S.clear();
	return totalTime;
}

int main () {
	int testCase;
	cin >> testCase;
	int N;
	vector<string> S;
	string str;
	float result;
	for (int t = 0; t < testCase; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> str;
			S.push_back(str);
		}
		result = typing(S, N);
		cout << result * 10 << endl;
		S.clear();
	}
	return 0;
}
