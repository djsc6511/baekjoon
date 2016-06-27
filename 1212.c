#include<stdio.h>

int main(void) {

	int num;
	int *temp8=malloc(sizeof(int) * 333334);
	int *temp2 = malloc(sizeof(int) * 1000000);
	scanf("%d", &num);
	int i = 0;
	int j;
	while(1) {
		if (num == 0)
			break;
		else {
			temp8[i] = num % 10;
			printf("%d\n", temp8[i]);
			
			num /= 10;
		}
		i++;
	}
	
	printf("%d", i);
	for (j=0; j > i; j++) {
		while (1) {
			temp2[j] = temp8[j] % 2;
		}
	}
		printf("%d", temp8[i-1]);
	return 0;
}