#include<cstdio>

using namespace std;

long long dp[111];

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int n;
		scanf("%d", &n);

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 3] + dp[i - 2];
		}

		printf("%lld\n", dp[n]);
	}

	return 0;
}