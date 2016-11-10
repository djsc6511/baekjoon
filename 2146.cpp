#include<cstdio>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int N;
int map[111][111] = { -1, };

int mx[4] = { 0,0,1,-1 };
int my[4] = { 1,-1,0,0 };
vector<pair<int, int>> v;

int abs(int x) {
	if (x >= 0) {
		return x;
	}
	else {
		return -x;
	}
}

bool isMovePossible(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) {
		return false;
	}
	else {
		return true;
	}
}

void dfs(int x, int y, int area) {
	map[x][y] = area;

	if (map[x + 1][y] ==1 && isMovePossible(x + 1, y)) dfs(x + 1, y, area);
	if (map[x - 1][y] == 1 && isMovePossible(x - 1, y)) dfs(x - 1, y, area);
	if (map[x][y + 1] == 1 && isMovePossible(x, y + 1)) dfs(x, y + 1, area);
	if (map[x][y - 1] == 1 && isMovePossible(x, y - 1)) dfs(x, y - 1, area);
}

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool check = false;
			if (map[i][j] == 1) {
				if (isMovePossible(i + 1, j) && map[i + 1][j] == 0) check = true;
				if (isMovePossible(i - 1, j) && map[i - 1][j] == 0) check = true;
				if (isMovePossible(i, j + 1) && map[i][j + 1] == 0) check = true;
				if (isMovePossible(i, j - 1) && map[i][j - 1] == 0) check = true;

				if (check) {
					v.push_back(make_pair(i, j));
				}
			}
		}
	}
	int area = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) dfs(i, j, area++);
		}
	}

	int min = 9999999;
	int dis = 0;

	for (int i = 0; i < v.size()-1; i++) {
		for (int j = 1; j < v.size(); j++) {
			if (map[v[i].first][v[i].second]
				!= map[v[j].first][v[j].second]) {
				dis = abs(v[i].first - v[j].first) +
					abs(v[i].second - v[j].second);
				if (dis < min) {
					min = dis;
				}
			}
			
		}
		
		
	}
	
	printf("%d", min -1);
	return 0;
}