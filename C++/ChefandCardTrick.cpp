#include <iostream>
#include <deque>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;

bool possibleToSort (deque <LLI> deck) {
	bool check = false;
	for (LLI i = 0; i < deck.size(); i++) {
		check = is_sorted(deck.begin(), deck.end(), less_equal<LLI>());
		if (check == true) {
			break;
		}
		deck.push_back(deck.front());
		deck.pop_front();
	}
	return check;
}

int main () {
	int testcase;
	cin >> testcase;
	LLI N;
	deque <LLI> deck;
	int element;
	for (int t = 0; t < testcase; t++) {
		cin >> N;
		for (LLI j = 0; j < N; j++) {
			cin >> element;
			deck.push_back(element);
		}
		if (possibleToSort(deck) == true) {
			cout << "YES" << endl; 
		} else {
			cout << "NO" << endl;
		}
		deck.clear();
	}
	return 0;
}
