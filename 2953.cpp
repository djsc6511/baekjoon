#include<stdio.h>
#include<vector>

using namespace std;
vector<int> sum;

int main(void) {
	sum.resize(10);
	int score[4];
	int temp=0;
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &score[j]);
		}
			
		for (int j = 0; j < 4; j++) {
			sum[i] += score[j];
		}
		printf("%d\n", sum[i]);
	}
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (sum[j] > sum[j + 1]) {
				int temp = sum[j];
				sum[j] = sum[j + 1];
				sum[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d\n", sum[i]);
	}
	return 0;
}