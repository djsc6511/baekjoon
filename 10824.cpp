#include<cstdio>
#include<string.h>
#include<stdlib.h>

using namespace std;
char stra[1000001];
char strb[1000001];
char strc[1000001];
char strd[1000001];

int main(void) {
	int a, b, c, d;

	long long unsigned int temp1, temp2;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	temp1 = a + c;
	temp2 = b + d;
	itoa(temp1,stra,10);
	itoa(temp2, strb, 10);

	strcat(stra, strb);

	printf("%s", stra);

	return 0;
}