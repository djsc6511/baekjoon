#include<cstdio>
#include<iostream>
#include<memory.h>

using namespace std;

int dp[33];
int row;

int main() {
	cin >> row;
	memset(dp, 0, sizeof(dp));

	dp[2] = 3;
	dp[4] = 11;

	for (int i = 6; i <= row; i+=2) {
		dp[i] += dp[i - 2] * 4 - dp[i - 4];
	}
	cout << dp[row] << endl;
	
	return 0;
}