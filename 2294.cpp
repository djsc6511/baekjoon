#include<cstdio>
#include<memory>
#include<algorithm>

using namespace std;

int coin[111];
int dp[11111];

int n, k;

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < 11111; i++) {
		dp[i] = 11111;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 11111) printf("-1\n");
	else printf("%d\n", dp[k]);
	return 0;
}