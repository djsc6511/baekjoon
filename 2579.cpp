#include<cstdio>

using namespace std;
int dp[333];

int solve(int index) {

}

int main(void) {
	int testcase;
	int num;
	scanf("%d", &testcase);

	for (int i = 1; i <= testcase; i++) {
		scanf("%d", &num);
		dp[i] = num;
	}
	return 0;
}