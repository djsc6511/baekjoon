#include<cstdio>

int N;
int graph[2001][2001];
bool visited[2001];
bool r_visited[2001];

void dfs(int n) {
	visited[n] = true;
	
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && graph[n][i]) {
			dfs(i);
		}
	}
}

void r_dfs(int n) {
	r_visited[n] = true;

	for (int i = 1; i <= N; i++) {
		if (!r_visited[i] && graph[i][n]) {
			r_dfs(i);
		}
	}
}

int main(void) {
	int pair, f, e;
	scanf("%d", &N);
	scanf("%d", &pair);
	for (int i = 0; i < pair; i++) {
		scanf("%d %d", &f, &e);
		graph[f][e] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[j] = false;
			r_visited[j] = false;
		}

		dfs(i);
		r_dfs(i);

		int count = 0;
		for (int j = 1; j <= N; j++) {
			if (visited[j] || r_visited[j]) {
				count += 1;
			}
		}
		printf("%d\n", N - count);

	}

	return 0;
}