#include<cstdio>
#include<algorithm>
using namespace std;

int main(void) {
	int appleA, appleB;
	int orangeA, orangeB;

	scanf("%d %d", &appleA, &orangeA);
	scanf("%d %d", &appleB, &orangeB);

	int tmp1 = appleA + orangeB;
	int tmp2 = orangeA + appleB;

	int result = min(tmp1, tmp2);
	printf("%d", result);
	return 0;
}