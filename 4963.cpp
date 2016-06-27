#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
using namespace std;


int dx[8] = { -1,0,0,1,-1,1,1,-1 };
int dy[8] = { 1,1,-1,0,0,-1,1,-1 };

int main(void) {
	int w, h;
	while (true) {
		scanf("%d %d", &w, &h);
		vector<vector<int>> map;
		if (w == 0 && h == 0)
			break;
		map.resize(h);

		for (int i = 0; i < h; i++)
			map[i].resize(w);

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				scanf("%d", &map[i][j]);
		}

		int count = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					count++;

					queue<pair<int, int>> q;

					q.push(make_pair(i, j));
					map[i][j] = 2;

					while (!q.empty()) {
						int hy = q.front().first;
						int hx = q.front().second;

						q.pop();

						for (int i = 0; i < 8; i++) {
							int nx = hx + dx[i];
							int ny = hy + dy[i];

							if (nx >= 0 && nx < w&& ny >= 0 && ny < h) {
								if (map[ny][nx] == 1) {
									map[ny][nx] = 2;
									q.push(make_pair(ny, nx));
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}