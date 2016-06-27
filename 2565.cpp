#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<pair<int, int>> p;
int n;
int dp[111];

int main(void) {
	
	int f_line, s_line;
	scanf("%d", &n);
	for (int i = 0; i < 111; i++)
		dp[i] = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &f_line,&s_line);
		p.push_back(make_pair(f_line, s_line));
	}

	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (p[i].second > p[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}

	printf("%d", n-result);
	return 0;
}