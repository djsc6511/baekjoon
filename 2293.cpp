#include<cstdio>
#include<memory.h>

using namespace std;

int dp[11111];
int coin[111];

int n, k;

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	
	dp[0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= coin[i]) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}

	printf("%d\n", dp[k]);
	return 0;
}