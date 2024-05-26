#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long grid[1000001];
int num, n, T;

int main() {
	cin >> T;

	grid[1] = 1;
	grid[2] = 2;
	grid[3] = 4;

	for (int tc = 0; tc < T; tc++) {
		cin >> n;

		if (grid[n] != 0) {
			cout << grid[n] % 1000000009 << "\n";
			continue;
		}

		for (int i = 4; i <= n; i++) {
			if (grid[i] != 0) {
				continue;
			}

			grid[i] = (grid[i - 3] + grid[i - 2] + grid[i - 1]) % 1000000009;
		}

		cout << grid[n] % 1000000009 << "\n";
	}

	return 0;
}