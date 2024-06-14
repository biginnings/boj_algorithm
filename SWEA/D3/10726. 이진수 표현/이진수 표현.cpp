#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, T, M;
int grid[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	grid[1] = 2;
	for (int i = 2; i < 31; i++) {
		grid[i] = grid[i - 1] << 1;
	}

	for (int i = 1; i <= 30; i++) {
		grid[i] -= 1;
	}

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		int b = grid[N] & M;

		if (grid[N] != b) cout << "#" << tc << " OFF\n";
		else cout << "#" << tc << " ON\n";
	}

	return 0;
}