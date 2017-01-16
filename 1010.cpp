#include<cstdio>
#include<iostream>
#include<memory.h>

using namespace std;

int cache[33][33];

int solve(int w, int e) {
	if (w == e) {
		return 1;
	}
	if (w == 0 || e == 0) {
		return 1;
	}

	int &ret = cache[w][e];

	if (ret != -1) {
		return ret;
	}

	ret = solve(w - 1, e - 1) + solve(w, e - 1);
	return ret;
}
int main() {
	int testcase;
	scanf("%d", &testcase);

	memset(cache, -1, sizeof(cache));
	while (testcase--) {
		int west, east;
		scanf("%d %d", &west, &east);
		printf("%d\n", solve(west, east));
	}
	return 0;
}