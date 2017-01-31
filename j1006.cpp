#include<cstdio>
#include<queue>
#include<algorithm>
#define INF 987654321

using namespace std;

int map[111][111];
bool isVisited[111][111];
int M, N;

int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

typedef struct {
	int x;
	int y;
	int dir;
	int dis;
	int moveCount;
} Point;

bool isMovePossible(int x, int y) {
	if (x<1 || x>N || y<1 || y>M) {
		return false;
	}
	else {
		return true;
	}
}

int abs(int a) {
	if (a >= 0) return a;
	else return -a;
}

struct cmp {
	bool operator()(Point &t, Point &u) {
		return t.dis > u.dis;
	}
};

int main() {
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			int n;
			scanf("%d", &n);

			if (n == 1) {
				map[i][j] = INF;
			}
			else {
				map[i][j] = n;
			}
		}
	}
	int fx, fy, fdir;
	int ex, ey, edir;
	scanf("%d %d %d", &fy, &fx, &fdir);
	scanf("%d %d %d", &ey, &ex, &edir);

	Point p;
	priority_queue<Point, vector<Point>, cmp> q;
	p.x = fx;
	p.y = fy;
	p.dir = fdir;
	p.dis = 0;
	p.moveCount = 0;
	q.push(p);

	isVisited[fy][fx] = true;
	
	int result = INF;
	while (!q.empty()) {
		int curX = q.top().x;
		int curY = q.top().y;
		int curDir = q.top().dir;
		int curDis = q.top().dis;
		int curMoveCnt = q.top().moveCount;
		/*
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == INF) {
					printf("# ");
				}
				else {
					printf("%d ", map[i][j]);
				}

			}
			printf("\n");
		}
		printf("\n");
		*/
		if (curX == ex && curY == ey) {
			if (curDir - edir == 0) {
				result = map[curY][curX];
			}
			else if ((curDir == 1 && edir == 2) || (curDir == 3 && edir == 4)
				|| (curDir == 2 && edir == 1) || (curDir == 4 && edir == 3)) {
				result = map[curY][curX] + 2;
			}
			else {
				result = map[curY][curX] + 1;
			}
		}

		q.pop();

		for (int i = 1; i <= 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isMovePossible(nextX, nextY) && map[nextY][nextX] == 0 && !isVisited[nextY][nextX]) {
				if (curDir == i) {
					isVisited[nextY][nextX] = true;
					if (curMoveCnt == 0) {
						curMoveCnt += 1;
						map[nextY][nextX] += map[curY][curX] + 1;
					}
					else {
						curMoveCnt += 1;
						map[nextY][nextX] += map[curY][curX];
						if (curMoveCnt == 3) {
							curMoveCnt = 0;
						}
					}
					
					Point np;
					np.x = nextX;
					np.y = nextY;
					np.dir = i;
					np.dis = map[nextY][nextX];
					np.moveCount = curMoveCnt;
					q.push(np);

				}
				else {
					if ((curDir ==1 && i ==2) || (curDir == 3 && i ==4) 
					|| (curDir == 2 && i == 1) || (curDir == 4 && i == 3)){
						isVisited[nextY][nextX] = true;
						curDis += 3;
						map[nextY][nextX] += map[curY][curX] + 3;

						Point np;
						np.x = nextX;
						np.y = nextY;
						np.dir = i;
						np.dis = map[nextY][nextX];
						np.moveCount = 1;

						q.push(np);
					}
					else {
						isVisited[nextY][nextX] = true;
						curDis += 2;
						map[nextY][nextX] += map[curY][curX] + 2;

						Point np;
						np.x = nextX;
						np.y = nextY;
						np.dir = i;
						np.dis = map[nextY][nextX];
						np.moveCount = 1;

						q.push(np);
					}
				}
			}
		}
	}

	printf("%d", result);

	return 0;
}