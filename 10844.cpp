#include<cstdio>

using namespace std;

long long dp[111][10];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}

			dp[i][j] %= 1000000000;
		}
	}

	long long result = 0;
	for (int i = 0; i <= 9; i++) {
		result += dp[n][i] % 1000000000;
	}

	printf("%d\n", result % 1000000000);
	return 0;
}