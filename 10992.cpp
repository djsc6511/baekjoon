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
			if (i == num-1) {
				printf("*");
			}
			else {
				if (i == j || i == -j) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			
		}
		printf("\n");
	}
	return 0;
}