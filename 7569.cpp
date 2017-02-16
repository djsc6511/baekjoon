#include<cstdio>
#include<iostream>
#include<queue>
#include<memory.h>

using namespace std;

int M, N, H;
int tomato[111][111][111];
bool isVisited[111][111][111];

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};

typedef struct {
	int x;
	int y;
	int z;
}Point;

bool isMovePossible(int y, int x, int z) {
	if (y<1 || y>N || x<1 || x>M || z<1 || z>H) return false;
	else return true;
}

queue<Point> q;
int tomato_count = 0;

int bfs() {
	int cx, cy, cz;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		cz = q.front().z;
		
		q.pop();

		for (int m = 0; m < 6; m++) {
			int nx = cx + dx[m];
			int ny = cy + dy[m];
			int nz = cz + dz[m];

			if (isMovePossible(ny, nx, nz) && tomato[nz][ny][nx] == 0) {
				tomato[nz][ny][nx] = tomato[cz][cy][cx] + 1;
				Point np;
				np.x = nx;
				np.y = ny;
				np.z = nz;
				q.push(np);
				tomato_count--;
				
			}
		}
	}
	
	if (tomato_count <= 0) return tomato[cz][cy][cx] - 1;
	return -1;
}
int main() {
	cin >> M >> N >> H;
	
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					Point p;
					p.x = k;
					p.y = j;
					p.z = i;
					q.push(p);
				}
				else if (tomato[i][j][k] == 0) {
					tomato_count++;
				}
			}
		}
	}

	printf("%d\n", bfs());
	

	return 0;
}