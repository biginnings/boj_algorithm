#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int m, v;

    bool operator<(Point other) const {
        if (m != other.m) return m > other.m;
        return v > other.v;
    }
};

int N, M, m, v;
int grid[100001];
priority_queue<Point> pq;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> m >> v;
        pq.push({ m, v });
    }

    int result = 0;
    int now_m = 0;
    while (!pq.empty()) {
        Point now = pq.top();
        pq.pop();

        for (int i = M; i >= 1; i--) {
            if (i - now.m < 1) break;
            if (grid[i - now.m] == 0) continue;
            grid[i] = grid[i] >= grid[i - now.m] + now.v ? grid[i] : grid[i - now.m] + now.v;
        }
        grid[now.m] = grid[now.m] >= now.v ? grid[now.m] : now.v;
    }
    for (int i = 1; i <= M; i++) {
        result = result >= grid[i] ? result : grid[i];
    }

    cout << result;
    return 0;
}