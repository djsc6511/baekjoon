#include<queue>
#include<stdio.h>
#include<vector>
using namespace std;

typedef struct {
	int p, cnt;
}Point;

int dir[] = { -1,1,0 }; //-1 +1 *2
vector<int> check;//방문한 곳인지 체크

int main(void) {
	check.resize(110000, 0);
	int N, K;
	scanf("%d %d", &N, &K);
	if (N == K) {
		printf("0");
		return 0;
	}
	queue<Point> q;
	Point p;
	p.p = N;
	p.cnt = 0;
	check[p.p] = 1;
	q.push(p);

	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		//-1 +1 *2
		for (int i = 0; i < 3; i++) {
			Point tmp;
			tmp.cnt = p.cnt + 1;

			tmp.p = dir[i] + p.p;
			if (tmp.p == p.p) tmp.p *= 2;

			if (tmp.p == K) {
				printf("%d", tmp.cnt);
				return 0;
			}
			if (check[tmp.p] ||(tmp.p<0 || tmp.p >100000))
				continue;
			check[tmp.p] = 1;
			q.push(tmp);
		}
	}
	
	return 0;
}