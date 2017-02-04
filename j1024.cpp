#include<cstdio>
#include<iostream>
#include<memory.h>
#define INF 987654321

using namespace std;

int M, N;
int map[555][555];
int cache[555][555];
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { 1, 0, 0, -1 };

int solve(int y, int x) {
	if (y == M && x == N) return 1;
	if (y<1 || x<1 || y>M || x>N) return 0;

	int &ret = cache[y][x];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[ny][nx] < map[y][x]) {
			ret += solve(ny, nx);
		}
	}

	return ret;
}
int main() {
	cin >> M >> N;
	memset(cache, -1, sizeof(cache));

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	cout << solve(1, 1) << endl;
	return 0;
}