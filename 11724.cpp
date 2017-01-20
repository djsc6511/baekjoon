#include<cstdio>
#include<queue>
#define INF 987654321

using namespace std;

int map[1111][1111];
bool isVisited[1111];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		map[u][v] = 1;
		map[v][u] = 1;
	}


	queue<int> q;

	int count = 0;
	
	for (int i = 1; i <= N; i++) {
		if (!isVisited[i]) {
			count++;
	
			q.push(i);

			while (!q.empty()) {
				int cur = q.front();

				q.pop();

				for (int i = 1; i <= N; i++) {
					if (!isVisited[i] && map[cur][i] == 1) {
						isVisited[i] = true;
						q.push(i);
					}
				}
			}
		}
	}

	printf("%d", count);

	return 0;
}