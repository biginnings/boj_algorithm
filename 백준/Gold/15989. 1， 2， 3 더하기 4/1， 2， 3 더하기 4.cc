#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long grid[10001];
int num, n, T;

int main() {
	cin >> T;

	grid[1] = 1;
	grid[2] = 2;
	grid[3] = 3;

	for (int i = 4; i <= 10000; i++) {
		grid[i] = grid[i - 3] + i / 2 + 1;
	}

	for (int tc = 0; tc < T; tc++) {
		cin >> n;

		cout << grid[n] << "\n";
	}

	return 0;
}