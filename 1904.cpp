#include<cstdio>
#include<string.h>
using namespace std;


int main(void) {
	int N;
	int c;
	int a = 1;
	int b = 2;
	scanf("%d", &N);
	if (N == 1) {
		printf("%d",a);
		return 0;
	}
		
	else if (N == 2) {
		printf("%d",b);
		return 0;
	}
	else {
		
		for (int i = 3; i <= N; i++) {
			c = a + b;
			c = c % 15746;
			//a = a % 15746;
			//b = b % 15746;
			
			a = b;
			b = c;

		}
		int result = c % 15746;

		printf("%d", result);
		return 0;
	}
	
}