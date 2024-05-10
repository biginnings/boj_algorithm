#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Point {
	long long sum, n;
};

struct Temp {
	int n, fake_n;
};

int N, a;
long long result = 0;
int dat[2000001];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a;

		dat[a]++;
	}
	
	for (int i = 1; i < 2000001; i++) {
		long long cnt = 0;
		for (int j = i; j < 2000001; j += i) {
			cnt += dat[j];

			if (cnt > 1) {
				result = result >= i * cnt ? result : i * cnt;
			}
		}
	}

	cout << result;

	return 0;
}