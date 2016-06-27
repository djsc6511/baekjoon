#include<cstdio>

using namespace std;
int tiger;
int cnt = 0;

int solve(int idx) {
	
	if (idx == 0)
		return cnt++;

	cnt += 2 * solve(idx) + solve(idx - 1);
	return cnt;
}

int main(void) {
	scanf("%d", &tiger);
	printf("%d",solve(tiger));

	return 0;
}