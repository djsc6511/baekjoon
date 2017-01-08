#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

vector<int> baskets;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		baskets.push_back(i + 1);
	}

	while (M--) {
		int i, j;
		scanf("%d %d", &i, &j);

		int n = i - 1;
		int m = j - 1;
		for (i; i <= j; i++) {
			if (n > m) {
				break;
			}
			int tmp = baskets[n];
			baskets[n] = baskets[m];
			baskets[m] = tmp;

			n++;
			m--;
			
		}
	}

	for (int i = 0; i < baskets.size(); i++) {
		printf("%d ", baskets[i]);
	}
	return 0;
}