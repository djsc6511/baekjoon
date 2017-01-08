#include<cstdio>
#include<vector>

using namespace std;

vector<int> baskets;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		baskets.push_back(0);
	}

	while (M--) {
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);

		for (i; i <= j; i++) {
			baskets[i-1] = k;
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", baskets[i]);
	}
	return 0;
}