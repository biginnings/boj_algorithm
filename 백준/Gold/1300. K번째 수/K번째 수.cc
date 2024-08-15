#include <iostream>

using namespace std;

long long n, k;

int main() {
	cin >> n >> k;

	long long left = 1; long long right = n * n;
	long long temp = 0;
	while (left < right) {
		long long mid = (left + right) / 2;
		temp = 0;

		for (long long i = 1; i <= n; i++) {
			if (mid / i >= n) {
				temp += n;
			}
			else if (mid / i > 0) {
				temp += mid / i;
			}
			else {
				break;
			}
		}

		if (temp >= k) {
			right = mid;
		}
		else if (temp < k) {
			left = mid + 1;
		}
	}

	cout << right;

	return 0;
}