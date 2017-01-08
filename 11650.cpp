#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> coordinates;

int main() {
	int testcase;
	scanf("%d", &testcase);
	
	while (testcase--) {
		int x, y;
		scanf("%d %d", &x, &y);

		coordinates.push_back(make_pair(x, y));
	}

	sort(coordinates.begin(), coordinates.end());

	for (int i = 0; i < coordinates.size(); i++) {
		printf("%d %d\n", coordinates[i].first, coordinates[i].second);
	}
	return 0;
}