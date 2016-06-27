#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int map[1000][1000];
int dx[4] = { 0,0,1,-1};
int dy[4] = { 1,-1,0,0};

typedef struct{
	int x;
	int y;
}point;

void bfs(int x, int y, int h) {
	point p = { x,y };
	map[x][y] = -1;
	queue<point> q;
	q.push(p);
	
	
	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			point np = { p.x + dx[i],p.y + dy[i] };
			

			if (map[np.x][np.y]>h) {
				map[np.x][np.y]=-1;
				q.push(np);
			}
		}
	}
	
}

int max(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

int min(int a, int b) {
	if (a >= b)
		return b;
	else
		return a;
}
int main(void) {
	int N;
	scanf("%d", &N);
	int mn = 101;
	int mx = -1;
	int tmp;
	int init_map[101][101] = {};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &tmp);
			mn = min(tmp, mn);
			mx = max(tmp, mx);
			init_map[i][j] = tmp;
		}
	}

	int result = -1;
	for (int h = mn - 1; h <= mx; h++) {
		int tmpresult = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = init_map[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] > h) {
					bfs(i, j, h);
					tmpresult++;
				}
			}
		}
		//printf("result=%d\n", result);
		//printf("tempresult=%d\n", tmpresult);
		if (result >= tmpresult)
			continue;
		else
			result = tmpresult;
	}

	printf("%d", result);
	return 0;
}