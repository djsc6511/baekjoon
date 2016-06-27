#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;

#define SIZE 1001

int N, M;

int graph[SIZE][SIZE];

bool visited[SIZE];

void dfs(int n) {
	visited[n] = true;
	printf("%d ", n);

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && graph[n][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int root) {
	visited[root] = true;

	queue<int> q;
	q.push(root);

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		printf("%d ", here);

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && graph[here][i] == 1) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	printf("\n");
}

int main(void) {
	int start;

	scanf("%d %d %d", &N, &M, &start);

	int f, t;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &f, &t);
		graph[f][t] = 1;
		graph[t][f] = 1;
	}

	memset(visited, false, SIZE);
	dfs(start);
	printf("\n");

	memset(visited, false, SIZE);
	bfs(start);
	return 0;
}