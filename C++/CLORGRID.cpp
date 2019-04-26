#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LLI;

string colorTheGrid(char **grid, LLI N, LLI M, LLI obstacle) {
    LLI total = N * M;
    LLI cells = total - obstacle;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (grid[i][j] == '#' || grid[i + 1][j] == '#' || grid[i][j + 1] == '#' || grid[i + 1][j + 1] == '#') {
                continue;
            } else {
                // cells -= 4;
                grid[i][j] = 'C';
                grid[i + 1][j] = 'C';
                grid[i][j + 1] = 'C';
                grid[i + 1][j + 1] = 'C';
            }
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'C') {
                count += 1;
            }
        }
    }
    if (cells == count) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
	    LLI N, M;
	    cin >> N >> M;
	    LLI obstacle = 0;
	    char **grid = new char*[N];
        for (int i = 0; i < N; i++) {
            grid[i] = new char[M];
        }
	    for (int i = 0; i < N; i++) {
	        for (int j = 0; j < M; j++) {
	            cin >> grid[i][j];
	            if (grid[i][j] == '#') {
	                obstacle += 1;
	            }
	        }
	    }
	    cout << colorTheGrid(grid, N, M, obstacle) << endl;
	}
	return 0;
}
