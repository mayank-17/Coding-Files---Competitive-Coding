#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i = 0; i < 10; i++) {
        string a;

        string b;

        cin >> a >> b;

        if (a > b) {
            cout << "a" << endl;
        } else if (a < b) {
            cout << "b" << endl;
        } else {
            cout << "e" << endl;
        }

        if (a.length() > b.length()) {
            cout << "A" << endl;
        } else if (a.length() < b.length()) {
            cout << "B" << endl;
        } else {
            cout << "E" << endl;
        }
    }

    return 0;
}
