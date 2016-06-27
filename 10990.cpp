#include<stdio.h>

int main(void) {
	int num;
	scanf("%d", &num);

	for (int i = 0; i<num; i++) {
		
		for (int j = num-1; j>-num; j--) {
			if (i == j || i==-j) {
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