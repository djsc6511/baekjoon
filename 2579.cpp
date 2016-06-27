#include<cstdio>

using namespace std;
int dp[333][3];
int score[333];
int testcase;

int max(int a, int b) {
	return a > b? a: b;
}
int main(void) {
	
	int num;
	scanf("%d", &testcase);

	for (int i = 1; i <= testcase; i++) {
		scanf("%d", &num);
		score[i] = num;
	}

	dp[1][1] = score[1];
	dp[1][2] = score[1];

	for (int i = 2; i <= testcase; i++) {
		dp[i][1] = dp[i - 1][2] + score[i];
		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];

	}

	printf("%d", max(dp[testcase][1], dp[testcase][2]));
	return 0;
}