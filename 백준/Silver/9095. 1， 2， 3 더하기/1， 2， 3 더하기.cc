#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int grid[12];
int N, T;

int main() {
	cin >> T;

	for (int tc = 0; tc < T; tc++) {

		grid[1] = 1;
		grid[2] = 2;
		grid[3] = 4;

		cin >> N;

		for (int i = 4; i <= N; i++) {
			grid[i] = grid[i - 3] + grid[i - 2] + grid[i - 1];
		}

		cout << grid[N] << "\n";
	}


	return 0;
}