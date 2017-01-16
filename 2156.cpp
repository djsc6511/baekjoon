#include<cstdio>
#include<memory.h>
#include<algorithm>

using namespace std;

int cache[1111];
int wine[111];

int main() {
	int testcase;
	scanf("%d", &testcase);

	for (int i = 1; i <= testcase; i++) {
		scanf("%d", &wine[i]);
	}

	cache[1] = wine[1];
	cache[2] = wine[1] + wine[2];

	for (int i = 3; i <= testcase; i++) {
		cache[i] = max(cache[i - 1], max(cache[i - 2] + wine[i], cache[i - 3] + wine[i - 1] + wine[i]));
	}

	printf("%d\n", cache[testcase]);
	return 0;
}