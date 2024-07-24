#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int y_r, x_r, y_b, x_b, d, cnt;

	bool operator<(Point other) const {
		return cnt > other.cnt;
	}
};

int N, M, target_y, target_x;
int grid[10][10], visited;
// 우 : 0, 좌 : 1, 하 : 2, 상 : 3
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };

int main() {
	cin >> N >> M;

	Point now_t = { -1, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char a;
			cin >> a;

			if (a == '#') {
				grid[i][j] = -1;
			}
			else if (a == 'B') {
				now_t.y_b = i;
				now_t.x_b = j;
			}
			else if (a == 'R') {
				now_t.y_r = i;
				now_t.x_r = j;
			}
			else if (a == 'O') {
				grid[i][j] = 3;
				target_y = i;
				target_x = j;
			}
		}
	}

	visited = 99999;
	priority_queue<Point> q;
	now_t.cnt = 0;
	now_t.d = -1;
	q.push(now_t);

	while (!q.empty()) {
		Point now = q.top();
		q.pop();
		now.cnt++;
		if (now.cnt > 10) continue;

		for (int i = 0; i < 4; i++) {
			if (now.d == i) continue;
			Point next = now;
			next.d = i;

			int dist = 1;
			int ny = next.y_r + dy[next.d] * dist;
			int nx = next.x_r + dx[next.d] * dist;

			while (grid[ny][nx] != -1) {
				if (ny == target_y && nx == target_x) {
					break;
				}
				dist++;
				ny = now.y_r + dy[next.d] * dist;
				nx = now.x_r + dx[next.d] * dist;
			}

			int dist_b = 1;
			int ny_b = next.y_b + dy[next.d] * dist_b;
			int nx_b = next.x_b + dx[next.d] * dist_b;

			while (grid[ny_b][nx_b] != -1) {
				if (ny_b == target_y && nx_b == target_x) {
					break;
				}
				dist_b++;
				ny_b = now.y_b + dy[next.d] * dist_b;
				nx_b = now.x_b + dx[next.d] * dist_b;
			}

			if (target_y == ny_b && target_x == nx_b) {
				continue;
			}
			else if(target_y == ny && target_x == nx ) {
				cout << now.cnt;
				return 0;
				//visited = visited <= now.cnt ? visited : now.cnt;
				//continue;
			}

			if (ny_b == ny && nx_b == nx) {
				if (dist_b > dist) {
					next = { ny - dy[next.d], nx - dx[next.d], ny_b - dy[next.d] * 2, nx_b - dx[next.d] * 2, next.d, next.cnt };
				}
				else {
					next = { ny - dy[next.d] * 2, nx - dx[next.d] * 2, ny_b - dy[next.d], nx_b - dx[next.d], next.d, next.cnt };
				}
			}
			else {
				next = { ny - dy[next.d], nx - dx[next.d], ny_b - dy[next.d], nx_b - dx[next.d], next.d, next.cnt };
			}

			q.push(next);
		}
	}

	cout << "-1";
}