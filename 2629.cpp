#include<stdio.h>
#include<algorithm>

using namespace std;

int chucount;
int chu_weight[33];
int ball;
int ball_weight[10];
int sum;
int tmp[50];

void check(int idx, int count) {
	if (idx == (chucount + ball))
		return;

	if (sum == ball_weight[idx])
		printf("Y");


	check(idx, count + 1);
	check(idx, count);
}

int main(void) {
	
	scanf("%d", &chucount);
	for (int i = 0; i < chucount; i++) 
		scanf("%d", &chu_weight[i]);

	scanf("%d", &ball);
	for (int i = 0; i < ball; i++) 
		scanf("%d", &ball_weight[i]);
	


	return 0;
}