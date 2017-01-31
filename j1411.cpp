#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int N;
int cache[111111];

int solve(int idx) {
	if (idx == 1) return 1;
	if (idx == 2) return 3;

	int &ret = cache[idx];
	if (ret != -1) {
		return ret % 20100529;
	}

	ret = solve(idx - 1) % 20100529 + solve(idx - 2) % 20100529 + solve(idx - 2) % 20100529;
	return ret % 20100529;
}
int main() {
	cin >> N;
	memset(cache, -1, sizeof(cache));

	cout << solve(N) << endl;
	return 0;
}