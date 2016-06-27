#include<stdio.h>

int abs(int num) {
	if (num > 0)
		return num;
	else
		return -num;
}
int main(void) {
	int num;
	scanf("%d", &num);

	for (int i = 0; i<num; i++) {

		for (int j = num - 1; j > -num; j--) {
			if (i == j || i == -j||((i-abs(j)>0)&&((i-j)%2==0))) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}