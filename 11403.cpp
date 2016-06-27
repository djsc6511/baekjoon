#include<cstdio>

int N;
int graph[101][101];
bool visited[101][101];

void dfs(int n, int here) {
	for (int i = 0; i <= N; i++) {
		if (!visited[n][i] && graph[here][i] == 1) {
			visited[n][i] = true;
			dfs(n, i);
		}
	}
}
int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			scanf("%d", &graph[i][j]);
	}

	for (int i = 1; i <= N; i++) {
		dfs(i, i);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	return 0;
}
