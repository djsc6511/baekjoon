#include<cstdio>

using namespace std;

int timer[3] = { 300,60,10 };

int main(void) {
	int t;
	scanf("%d", &t);
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp = t;
	while (tmp >= 300) {
		i++;
		tmp = t - 300 * i;
		if (tmp == t) {
			i++;
			break;
		}
			
		
	}
	//printf("%d", tmp);
	t = tmp;
	while (tmp >= 60) {
		j++;
		tmp = t - 60 * j;
		if (tmp == t) {
			j++;
			break;
		}
			
		
	}
	t = tmp;
	while (tmp >= 10) {
		k++;
		tmp = t - 10 * k;

		if (tmp == t) {
			k++;
			
			break;
		}	
	}
	if (tmp == 0) 
		printf("%d %d %d", i, j, k);
	else
		printf("-1");


	return 0;
}