#include<cstdio>
#include<string.h>

using namespace std;
int cache[1111];
int solve(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;

	int &ret = cache[n];

	if (ret != -1)
		return ret % 10007;

	ret = solve(n - 1) % 10007 + solve(n - 2) % 10007+solve(n-2)%10007;
	int _ret = ret % 10007;
	return _ret;

}
int main(void) {
	int n;
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));

	printf("%d", solve(n));
	return 0;
}