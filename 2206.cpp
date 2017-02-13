#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>
#define INF 987654321

using namespace std;

int N, M;
char map[1111][1111];
int value[1111][1111][2];
bool isVisited[1111][1111];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

typedef struct {
	int y;
	int x;
	int crash;
}Point;

int res = INF;

bool isPossibleMove(int y, int x) {
	if (y > N || y<1 || x>M || x < 1) return false;
	else return true;
}

int bfs() {
	memset(isVisited, false, sizeof(isVisited));

	queue<Point> q;
	Point p;
	p.x = 1;
	p.y = 1;
	p.crash = 0;
	q.push(p);
	isVisited[1][1] = true;
	value[1][1][0] = 1;

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int ccrash = q.front().crash;
		
		if (cy == N && cx == M) {
			return res = min(value[N][M][0], value[N][M][1]);
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (isPossibleMove(ny, nx) && map[ny][nx] == '0' && (value[ny][nx][ccrash] > value[cy][cx][ccrash] + 1)) {
				value[ny][nx][ccrash] = value[cy][cx][ccrash] + 1;
				
				Point p;
				p.y = ny;
				p.x = nx;
				p.crash = ccrash;
				q.push(p);
			}

			if (ccrash == 0 && isPossibleMove(ny, nx) && map[ny][nx] == '1' && (value[ny][nx][1] > value[cy][cx][0] + 1)) {
				value[ny][nx][1] = value[cy][cx][0] + 1;
				
				Point p;
				p.y = ny;
				p.x = nx;
				p.crash = 1;
				q.push(p);
			}

			
		}
	}
}
int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char t;
			cin >> t;
			map[i][j] = t;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 2; k++) {
				value[i][j][k] = INF;
			}
		}
	}

	res = bfs();
	if (value[N][M][0] == INF && value[N][M][1] == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", res);
	}
	return 0;
}