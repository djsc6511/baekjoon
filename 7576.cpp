#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int well[1111][1111];
typedef pair<int, int> p;
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
int result = 1;
int main(void) {
	int tomato = 0;
	queue<p> q;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &well[i][j]);
			if (well[i][j] == 0 || well[i][j] == 1)
				tomato++;
			if (well[i][j] == 1)
				q.push(p(i, j));
		}
	}

	while (!q.empty()) {
		p here = q.front();
		int hx = here.first;
		int hy = here.second;

		q.pop();
		tomato--;

		for (int i = 0; i < 4; i++) {
			int nx = hx + x[i];
			int ny = hy + y[i];

			if (nx<1 || nx>N || ny<1 || ny>M)
				continue;
			if (well[nx][ny] == 0) {
				well[nx][ny] = well[hx][hy] + 1;
				
				if (result < well[nx][ny])
					result = well[nx][ny];
				q.push(p(nx, ny));
			}
			

		}

	}
	
	if (tomato == 0)
		printf("%d", result - 1);
	else
		printf("-1");
	return 0;
}