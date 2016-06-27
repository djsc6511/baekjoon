#include<cstdio>
#include<algorithm>
using namespace std;

int main(void) {
	int n;
	int box[1111];
	int dp[1111] = {};
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &box[i]);
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}

	printf("%d", result);
	return 0;
}