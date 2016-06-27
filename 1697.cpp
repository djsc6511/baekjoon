#include<stdio.h>
#include<queue>

using namespace std;

int main(void){
	int N, K;
	int visited[100001] = {0,};
	int result = 0;
	queue<int> q;
	scanf("%d %d", &N, &K);

	q.push(N);
	visited[N] = 1;

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		if (p == K) {
			result=visited[p] - 1;
			break;
		}
			

		if (p - 1 >= 0 && visited[p-1] == 0) {
			visited[p - 1] = visited[p] + 1;
			q.push(p - 1);
		}

		if (p + 1 <= 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}

		if (p * 2 <= 100000 && visited[p * 2] == 0) {
			visited[p * 2] = visited[p] + 1;
			q.push(2 * p);
		}
	}

	printf("%d", result);
	return 0;
}