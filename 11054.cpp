#include<cstdio>
#include<algorithm>
using namespace std;

int main(void) {
	int n;
	int a[1111];
	int dp[2][1111] = {};
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	//왼쪽부터
	for (int i = 0; i < n; i++) {
		dp[0][i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp[0][i] = max(dp[0][i], dp[0][j] + 1);
			}
		}
	}
	
	//오른쪽부터
	for (int i = n-1; i >= 0; i--) {
		dp[1][i] = 1;
		for (int j = n-1; j >= i;j--){
			if (a[i] > a[j]) {
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
			}

		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[0][i] + dp[1][i]);
	}
	printf("%d", result-1);
	return 0;
}