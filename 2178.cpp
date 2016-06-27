#include<cstdio>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

int N, M;
int map[101][101];
bool visited[10001];

typedef struct {
	int x;
	int y;
	int t;
}point;

int x_move[4] = { 0,1,0,-1 };
int y_move[4] = { 1,0,-1,0 };

int main(void) {
	int N, M;
	char cgraph[123][123];
	int graph[123][123] = {};
	
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%s", cgraph[i]+1);
		printf("%s\n", cgraph[i] + 1);
		
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			graph[i][j] = cgraph[i][j]-'0';

			if (graph[i][j] == 1) {
				graph[i][j] = -1;
			}
		}
	}

	queue<point> q;
	point p = { 1,1,1 };
	q.push(p);

	graph[1][1] = 1;
	int x, y, t;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		x = p.x;
		y = p.y;
		t = p.t;

		for (int i = 0; i < 4; i++) {
			int nx = x + x_move[i];
			int ny = y + y_move[i];

			if (graph[nx][ny] == -1) {
				graph[nx][ny] = t + 1;
				point t_p = { nx,ny,t + 1 };
				q.push(t_p);
			}
		}
	}
	printf("%d\n", graph[N][M]);
	return 0;
}