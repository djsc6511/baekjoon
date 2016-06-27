#include<cstdio>

using namespace std;
int dp[1111111];

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 0;
	for(int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	printf("%d", dp[N]);
	return 0;
}