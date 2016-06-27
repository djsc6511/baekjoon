#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int s[1111];
int d[1111];
int a;

int solve(int idx) {
	if (idx == a) {
		return 0;
	}

	int &ret = d[idx];

	if (ret != -1) {
		return ret;
	}
	ret = 1;
	for (int i = idx + 1; i <= a; i++) {
		if (s[idx] < s[i]) {
			ret = max(ret, 1 + solve(i));
		}
	}

	return ret;
}
int main(void) {
	
	scanf("%d", &a);
	for (int i = 0; i < 1111; i++) {
		d[i] = -1;
	}
	for (int i = 0; i < a; i++) {
		scanf("%d", &s[i]);
	}

	int res = 0;
	for (int i = 0; i < a; i++) {
		res = max(res, solve(i));
	}

	printf("%d", res);
	return 0;
}