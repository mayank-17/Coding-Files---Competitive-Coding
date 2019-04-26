#include <bits/stdc++.h>

using namespace std;

int rec(int a, int b, int c){
	double inc = ((b - a + 1)*1.0)/((c + 2)*1.0);
	if(inc < 1.0){
		inc = 1.0;
	}
	return (a + int(inc));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, c, t = 1000, ns = 0;
	cin >> N >> c;
	int n1 = 1, n2 = N;
	int inp;
	while(n1 < n2){
		int y = rec(n1, n2, c);
		cout << 1 << " " << y << endl;
		cin >> inp;
		if(inp == 0){
			ns = y;
			n1 = y + 1;
			t--;
		}
		else{
			if(inp = 1){
				cout << 2 << endl;
				t -= (c + 1);
				n1 = ns;
				n2 = y - 1;
			}
			else{
				n1 = ns;
				n2 = n1;
			}
		}
	}
	inp = 0;
	while(inp == 0){
		ns++;
		cout << 1 << " " << ns << endl;
		cin >> inp;
	}

	cout << 3 << " " << ns << endl;
	return 0;
}
