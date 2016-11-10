#include<cstdio>
#include<queue>

using namespace std;

int map[111][111] = { -1, };
int N, needX, needY, testcase, x, y;
bool isvisited[111] = { false, };
int ncount = 0;

int main() {
	scanf("%d", &N);
	scanf("%d %d", &needX, &needY);
	scanf("%d", &testcase);

	while (testcase--) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}

	queue<pair<int, int>> q;

	q.push(make_pair(needX, 0));

	int count = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int dis = q.front().second;
		if (x == needY) {
			count = dis;
			break;
		}
		isvisited[x] = true;
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!isvisited[i] && map[x][i] == 1) {
				q.push(make_pair(i, dis + 1));
			}
		}
	}

	if (count == 0) {
		printf("-1");
	}
	else {
		printf("%d", count);
	}
	return 0;
}