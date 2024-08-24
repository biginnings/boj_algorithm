#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N, M;
int parent[1000];

int find(int a) {
	if (parent[a] == a) return a;

	return parent[a] = find(parent[a]);
}

void makeUnion(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa != pb) parent[pb] = pa;
}

int main(void)
{
	int ans;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);
		makeUnion(x, y);
	}

	ans = 0;
	for (int i = 2; i <= N; i++)
		if (find(i) == find(1)) ans++;

	printf("%d\n", ans);

	return 0;
}