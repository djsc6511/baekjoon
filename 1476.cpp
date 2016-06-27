#include<cstdio>

using namespace std;

int main(void) {
	int E, S, M;
	int tmpE = 1;
	int tmpS = 1;
	int tmpM = 1;
	scanf("%d %d %d", &E, &S, &M);
	int count = 1;
	while (E != tmpE || S != tmpS || M != tmpM) {
		
		tmpE++;
		tmpS++;
		tmpM++;
		if (tmpE > 15)
			tmpE = 1;
		if (tmpS > 28)
			tmpS = 1;
		if (tmpM > 19)
			tmpM = 1;

		
		count++;
	}

	printf("%d", count);
	return 0;
}