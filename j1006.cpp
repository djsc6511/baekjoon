#include<cstdio>
#include<queue>
#include<algorithm>
#define INF 987654321

using namespace std;

int map[111][111];
bool isVisited[111][111];
int M, N;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

typedef struct {
	int x;
	int y;
	int dir;
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
	queue<Point> q;
	p.x = fx;
	p.y = fy;
	p.dir = fdir;
	p.moveCount = 0;
	q.push(p);

	isVisited[fy][fx] = true;

	int result = 0;
	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int curDir = q.front().dir;
		int curMoveCnt = q.front().moveCount;

		if (curX == ex && curY == ey) {
			if (curDir - edir == 0) {
				result = map[curY][curX];
				break;
			}
			else if (abs(curDir - edir) == 2 || abs(curDir - edir) == 3) {
				result = map[curY][curX] + 1;
				break;
			}
			else {
				result = map[curY][curX] + 2;
				break;
			}
			
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isMovePossible(nextX, nextY) && map[nextY][nextX] == 0 && !isVisited[nextY][nextX]) {
				if (curDir == i + 1) {
					isVisited[nextY][nextX] = true;
					if (curMoveCnt == 0) {
						curMoveCnt += 1;
						map[nextY][nextX] += map[curY][curX] + 1;
					}
					else {
						curMoveCnt += 1;
						map[nextY][nextX] = map[curY][curX];
						if (curMoveCnt == 3) {
							curMoveCnt = 0;
						}
					}
					
					Point np;
					np.x = nextX;
					np.y = nextY;
					np.dir = i + 1;
					np.moveCount = curMoveCnt;
					q.push(np);

				}
				else {
					if (curDir - i == 1) {
						isVisited[nextY][nextX] = true;
						map[nextY][nextX] += map[curY][curX] + 3;

						Point np;
						np.x = nextX;
						np.y = nextY;
						np.dir = i + 1;

						q.push(np);
					}
					else {
						isVisited[nextY][nextX] = true;
						map[nextY][nextX] += map[curY][curX] + 2;

						Point np;
						np.x = nextX;
						np.y = nextY;
						np.dir = i + 1;

						q.push(np);
					}
				}
			}
		}
	}

	printf("%d", result);

	return 0;
}