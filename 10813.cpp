#include<cstdio>
#include<vector>

using namespace std;

vector<int> baskets;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		baskets.push_back(i);
	}

	while (M--) {
		int i, j;
		scanf("%d %d", &i, &j);

		int tmp = baskets[j-1];
		baskets[j-1] = baskets[i-1];
		baskets[i-1] = tmp;
	}

	for (int i = 0; i < baskets.size(); i++) {
		printf("%d ", baskets[i]);
	}
	return 0;
}