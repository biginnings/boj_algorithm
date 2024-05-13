#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <unordered_set>

using namespace std;

int N, level = 1;
int visited[100001];
vector<int> v;
vector<int> grid;
vector<unordered_set<int>> vs(100001, unordered_set<int>());


void solve(int num, int prev_num) {
	if (num > N) return;
	if (visited[num] == 1) return;
	if (vs[prev_num].find(num) != vs[prev_num].end()) {
		v.push_back(prev_num);
		visited[num] = 1;
		level++;
		if (level >= N) return;
		solve(grid[level], num);
	}
	else {
		if (v.size() < 1) return;
		int next_num = v[v.size() - 1];
		v.pop_back();
		solve(num, next_num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;

		vs[a].insert(b);
		vs[b].insert(a);
	}

	for (int i = 0; i < N; i++) {
		cin >> a;
		grid.push_back(a);
	}

	if (grid[0] == 1) {
		visited[1] = 1;
		solve(grid[1], 1);
	}
	else {
		cout << "0";
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			cout << "0";
			return 0;
		}
	}

	cout << "1";
	return 0;
}