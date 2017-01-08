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
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);

		int begin = i - 1;
		int end = j - 1;
		int mid = k - 1;

		vector<int> tmp;

		for (int m = mid; m <= end; m++) {
			tmp.push_back(baskets[m]);
		}

		for (int b = begin; b < mid; b++) {
			tmp.push_back(baskets[b]);
		}

		int n = 0;
		for (int b = begin; b <= end; b++) {
			baskets[b] = tmp[n++];
		}
	}

	for (int i = 0; i < baskets.size(); i++) {
		printf("%d ", baskets[i]);
	}
	return 0;
}