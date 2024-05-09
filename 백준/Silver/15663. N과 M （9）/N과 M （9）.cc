#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

struct Point {
	int a;
	int b;
};

int N, M;
Point visited[10001];
vector<int> v;
vector<string> c_v;
string s;

void dfs(int level, int depth, string t_s) {
	if (level == depth) {
		s += (t_s + "\n");
		return;
	}

	int grid[10001] = { 0, };

	for (int i = 0; i < N; i++) {
		if (grid[v[i]] == 1 || visited[v[i]].a == visited[v[i]].b) {
			continue;
		}
		grid[v[i]] = 1;
		visited[v[i]].b++;
		string temp = t_s + c_v[i] + " ";
		dfs(level + 1, depth, temp);
		visited[v[i]].b--;
	}
}

int main() {
	cin >> N >> M;

	int a = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		visited[a].a++;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		c_v.push_back({ to_string(v[i]), false });
	}

	dfs(0, M, "");

	cout << s;
	
	return 0;
}