#include<cstdio>
#include<string.h>
using namespace std;
int N;

long long cache[100];

long long check(int N) {
	if (N == 1)
		return 1;
	if (N == 2)
		return 1;

	long long &count = cache[N];
	if (count != -1) return count;
	
	count = check(N - 1) + check(N - 2);
	return count;
}

int main(void) {
	//int N;
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	printf("%lld",check(N));
	return 0;
}