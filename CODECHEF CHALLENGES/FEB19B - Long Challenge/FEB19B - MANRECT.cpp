#include <iostream>
#define ui unsigned int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ui a, b, c, d, e;
        cout << "Q 0 0" << endl;
        cin >> a;
        cout << "Q 0 1000000000" << endl;
        cin >> b;
        cout << "Q 1000000000 1000000000" << endl;
        cin >> c;
        cout << "Q 1000000000 0" << endl;
        cin >> d;
        cout << "Q 0 " << (a - b + 1000000000) / 2 << endl;
        cin >> e;
        ui x1, x2, y1, y2;
        x1 = e;
        y1 = a - x1;
        x2 = 1000000000 + y1 - d;
        y2 = 1000000000 + x1 - b;
        cout << "A " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        int grader;
        cin >> grader;
        if (grader < 0)
        {
            break;
        }
    }
    return 0;
}