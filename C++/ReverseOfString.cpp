#include <bits/stdc++.h>
#include <string>
using namespace std;

void reverseOfString(string& str) {
	int len = str.length();
	
	for (int i = 0; i < len / 2; i++) {
		swap(str[i], str[len - i - 1]);
	}
}

int main () {
	string str;
	getline(cin, str);
	reverseOfString(str);
	cout << str;
	return 0;
}
