#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, M;
long long grid[1001][1001];

int main() {
	cin >> T;

	grid[1][1] = 1;
	grid[2][1] = 1;
	grid[2][2] = 1;
	grid[3][1] = 1;
	grid[3][2] = 2;
	grid[3][3] = 1;

	for (int i = 4; i < 1001; i++) {
		grid[i][i] = grid[i - 1][i - 1];

		for (int j = 1; j < i; j++) {
			if (j - 1 > i) break;
			grid[i][i - j] = (grid[i - 1][i - j - 1] + grid[i - 2][i - j - 1] + grid[i - 3][i - j - 1]) % 1000000009;
		}
	}

	for (int tc = 0; tc < T; tc++) {
		cin >> N >> M;

		cout << grid[N][M] << "\n";
	}



	return 0;
}