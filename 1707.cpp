#include<cstdio>
#include<vector>
#define INF 987654321

using namespace std;

vector<vector<int>> map;
bool isVisited[22222];

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int v, e;
		scanf("%d %d", &v, &e);

		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				map[i][j] = INF;
			}
		}
		for (int i = 1; i <= e; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}

		for (int i = 1; i <= e; i++) {
			if (!isVisited[i]) {

			}
		}
	}
	return 0;
}