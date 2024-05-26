#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int grid[11];
int num, n;
vector<string> v[11];

int main() {
	cin >> num >> n;

	v[1].push_back("1");
	v[2].push_back("11");
	v[2].push_back("2");
	v[3].push_back("12");
	v[3].push_back("21");
	v[3].push_back("3");
	v[3].push_back("111");

	if (num < 4) {
		sort(v[num].begin(), v[num].end());

		if (n <= v[num].size()) {
			for (int i = 0; i < v[num][n-1].size(); i++) {
				cout << v[num][n - 1][i];
				if (i != v[num][n-1].size() - 1) {
					cout << "+";
				}
			}
		}
		else {
			cout << -1;
		}

		return 0;
	}
	for (int i = 4; i <= num; i++) {
		for (int j = 1; j <= 3; j++) {
			int a = i - j;
			for (int z = 0; z < v[a].size(); z++) {
				v[i].push_back(v[a][z] + (char)(j + '0'));
			}
		}
	}

	sort(v[num].begin(), v[num].end());

	if (n <= v[num].size()) {
		for (int i = 0; i < v[num][n - 1].size(); i++) {
			cout << v[num][n - 1][i];
			if (i != v[num][n - 1].size() - 1) {
				cout << "+";
			}
		}
	}
	else {
		cout << -1;
	}

	return 0;
}