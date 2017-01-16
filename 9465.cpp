#include<cstdio>
#include<algorithm>

using namespace std;

int dp[111111][2];
int sticker[111111][2];

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &sticker[j][i]);
			}
		}

		dp[1][0] = sticker[1][0];
		dp[1][1] = sticker[1][1];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + sticker[i][0]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + sticker[i][1]);
		}
		printf("%d\n", max(dp[n][0], dp[n][1]));
	}
	return 0;
}