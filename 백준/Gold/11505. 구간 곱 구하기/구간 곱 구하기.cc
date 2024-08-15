#include <iostream>

using namespace std;

int N, M, K;
long long tree[4004000];

void update(int left, int right, int node, int index, long long value) {
	if (index < left || right < index) return;

	if (left == right) {
		tree[node] = value;
		return;
	}

	int mid = (left + right) / 2;
	int leftNodeIndex = node * 2;
	int rightNodeIndex = node * 2 + 1;

	update(left, mid, leftNodeIndex, index, value);
	update(mid + 1, right, rightNodeIndex, index, value);

	tree[node] = (tree[leftNodeIndex] * tree[rightNodeIndex]) % 1000000007;
}

long long getsum(int left, int right, int a, int b, int node) {
	if (b < left || right < a) return 1;
	if (a <= left && right <= b) return tree[node];

	int mid = (left + right) / 2;

	return (getsum(left, mid, a, b, node * 2) * getsum(mid + 1, right, a, b, node * 2 + 1)) % 1000000007;
}

int main() {
	cin >> N >> M >> K;

	long long a = 0;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		update(1, N, 1, i, a);
	}

	for (int i = 0; i < M + K; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		if (x == 1) {
			update(1, N, 1, y, z);
		}
		else {
			cout << getsum(1, N, y, z, 1) << "\n";
		}
	}

	return 0;
}