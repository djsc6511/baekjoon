#include<cstdio>
#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;

int cache[111][11111];
int T, k;
vector<pair<int, int >> coin;

int solve(int n, int v) {
	if (v == 0) return 1;
	if (n >= k) return 0;

	int &ret = cache[n][v];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int i = 0; i <= coin[n].second; i++) {
		if (v - coin[n].first * i >= 0) {
			ret += solve(n + 1, v - coin[n].first * i);
		}
	}

	return ret;
}
int main() {
	cin >> T >> k;

	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < k; i++) {
		int value, num;
		cin >> value >> num;
		coin.push_back(make_pair(value, num));
	}

	printf("%d\n", solve(0, T));
	return 0;
}