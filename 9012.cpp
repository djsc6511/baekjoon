#include<stdio.h>

int abs(int num) {
	if (num >= 0)
		return num;
	else
		return -num;
}
int main(void) {
	int num[5][5];
	int tmp = 0;
	int sum = 0;
	for (int i = 0; i < 5; i++) {

		scanf("%d %d %d %d %d", &num[i][0], &num[i][1], &num[i][2], &num[i][3], &num[i][4]);

	}

	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += abs(num[i][j]);
		}
		if (abs(num[i][i]) >= (sum - abs(num[i][i])))
			tmp += 0;
		else
			tmp += 1;

	}

	if (tmp == 0)
		printf("yes");
	else
		printf("no");
	return 0;
}