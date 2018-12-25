#include <bits/stdc++.h>

using namespace std;

vector < int > solve4(vector < int > vec){
	vector < int > ans(4, 0);
	ans[2] = (vec[0]^(vec[1]^vec[2]));
	ans[3] = (vec[1]^(vec[2]^vec[3]));
	ans[0] = (vec[2]^ans[2]^ans[3]);
	ans[1] = (vec[1]^ans[2]^ans[3]);
	return ans;
}

vector < int > solve5(vector < int > v){
	vector < int > ans(5, 0);
	ans[0] = (v[1]^(v[2]^v[4]));
	ans[1] = (v[0]^(v[2]^v[3]));
	ans[2] = (v[0]^(ans[0]^ans[1]));
	ans[3] = (v[1]^(ans[1]^ans[2]));
	ans[4] = (v[2]^(ans[2]^ans[3]));
	return ans;
}

vector < int > solve7(vector < int > v){
	vector < int > ans(7, 0);
	ans[0] = (v[0]^v[2]^v[3]^v[5]^v[6]);
	ans[1] = (v[0]^v[1]^v[3]^v[4]^v[6]);
	ans[2] = (v[0]^ans[0]^ans[1]);
	ans[3] = (v[1]^ans[1]^ans[2]);
	ans[4] = (v[2]^ans[2]^ans[3]);
	ans[5] = (v[3]^ans[3]^ans[4]);
	ans[6] = (v[4]^ans[4]^ans[5]);
	return ans;
}

void inputFunction(int k, int n, vector < int >& vec){
	for(int i = 0; i < n; i++){
		cout << 1 << " " << k + (i%n) << " " << k + (i + 1)%n << " " << k + (i + 2)%n << endl;
		cin >> vec[i];
	}
}

void f0(int n){
	vector < int > ans(n, 0);
	for(int i = 1; i < n; i+= 4){
		vector < int > vec(4, 0);
		inputFunction( i, 4, vec);
		vector < int > temp(4, 0);
		temp = solve4(vec);
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
	}
	cout << 2 << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	int inp;
	cin >> inp;
}

void f1(int n){
	vector < int > ans(n, 0);
	{
		vector < int > vec(5, 0);
		inputFunction(1, 5, vec);
		vector < int > temp(5, 0);
		temp = solve5(vec);
		int i = 1;
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
		ans[i + 3] = temp[4];
	}

	for(int i = 6; i < n; i+= 4){
		vector < int > vec(4, 0);
		inputFunction( i, 4, vec);
		vector < int > temp(4, 0);
		temp = solve4(vec);
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
	}

	cout << 2 << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	int inp;
	cin >> inp;

}

void f2(int n){
	vector < int > ans(n, 0);
	{
		vector < int > vec(5, 0);
		inputFunction(1, 5, vec);
		vector < int > temp(5, 0);
		temp = solve5(vec);
		int i = 1;
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
		ans[i + 3] = temp[4];
	}

	{
		vector < int > vec(5, 0);
		inputFunction(6, 5, vec);
		vector < int > temp(5, 0);
		temp = solve5(vec);
		int i = 6;
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
		ans[i + 3] = temp[4];
	}

	for(int i = 11; i < n; i+= 4){
		vector < int > vec(4, 0);
		inputFunction( i, 4, vec);
		vector < int > temp(4, 0);
		temp = solve4(vec);
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
	}

	cout << 2 << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	int inp;
	cin >> inp;
}

void f3(int n){
	vector < int > ans(n, 0);
	{
		vector < int > vec(7, 0);
		inputFunction(1, 7, vec);
		vector < int > temp(7, 0);
		temp = solve7(vec);
		int i = 1;
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
		ans[i + 3] = temp[4];
		ans[i + 4] = temp[5];
		ans[i + 5] = temp[6];
	}

	for(int i = 8; i < n; i+= 4){
		vector < int > vec(4, 0);
		inputFunction( i, 4, vec);
		vector < int > temp(4, 0);
		temp = solve4(vec);
		ans[i - 1] = temp[0];
		ans[i + 0] = temp[1];
		ans[i + 1] = temp[2];
		ans[i + 2] = temp[3];
	}

	cout << 2 << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	int inp;
	cin >> inp;
}

void f(){
	int N;
	cin >> N;

	if(N%4 == 0){
		f0(N);
	}

	if(N%4 == 1){
		f1(N);
	}

	if(N%4 == 2){
		f2(N);
	}

	if(N%4 == 3){
		f3(N);
	}
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		f();
	}
	return 0;
}
