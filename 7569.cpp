#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int M, N, H;
int tomato[111][111][111];

int dx[6] = {-1, 0, 1, 0, 0, 0 };
int dy[6] = { 0, -1, 0, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

typedef struct Point{
	int x;
	int y;
	int z;
} Point;

queue<Point> q;

bool isMovePossible(int x, int y, int z) {
	if (x<0 || x>M || y<0 || y>N || z<0 || z>H) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int count = 0;
	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < 111; i++) {
		for (int j = 0; j < 111; j++) {
			for (int k = 0; k < 111; k++) {
				tomato[k][j][i] = 11111;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &tomato[k][j][i]);
				
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[k][j][i] == 1) {
					for (int m = 0; m < 6; m++) {
						int nx = k + dx[m];
						int ny = j + dy[m];
						int nz = i + dz[m];

						if (nx == 0 || ny == 0 || nz == 0) {
							Point p;
							p.x = k;
							p.y = j;
							p.z = i;
							q.push(p);
							break;
						}
					}
				}

				if (tomato[k][j][i] == 1 || tomato[k][j][i] == 0) {
					count++;
				}
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (isMovePossible(nx, ny, nz) && tomato[nx][ny][nz] == 0) {
				tomato[nx][ny][nz] = 1;
				Point p;
				p.x = nx;
				p.y = ny;
				p.z = nz;

				q.push(p);
			}
		}
	}
	
	int result = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[k][j][i] == 1) {
					result++;
				}
			}
		}
	}

	if (count == result) printf("0\n"); 
	else printf("-1\n");
	
	return 0;
}