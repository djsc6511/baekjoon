#include<cstdio>
#include<utility>
#include<queue>
#include<vector>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int M, N, K;
vector<vector<int>> map;
int cnt;


int main(void) {
	int testcase;

	int row, col;
	scanf("%d", &testcase);
	
	while (testcase--) {
		scanf("%d %d %d", &M, &N, &K);
		map.resize(M);
		for (int i = 0; i < M; i++) {
			map[i].resize(N);
		}
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &row,&col);
			map[row][col] = 1;
		}
		cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				
				if (map[i][j] == 1) {
					cnt++;

					queue < pair<int, int>> q;
					q.push(make_pair(i, j));

					map[i][j] = 2;

					while (!q.empty()) {
						int hx = q.front().first;
						int hy = q.front().second;

						q.pop();

						for (int k = 0; k < 4; k++) {
							int nx = hx + dx[k];
							int ny = hy + dy[k];

							if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
								if (map[nx][ny] == 1) {
									map[nx][ny] = 2;
									q.push(make_pair(nx, ny));
									
								}

							}
						}
					}
				}
					
			}
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}