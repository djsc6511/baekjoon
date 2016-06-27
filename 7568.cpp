#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int height[66];
int weight[66];
int main(void) {
	int cnt = 0;
	int testcase;
	int result[66];
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		
		scanf("%d %d", &height[i], &weight[i]);

	}
	for (int i = 0; i < testcase; i++) {
		cnt = 0;
		for (int j = 0; j < testcase; j++) {
			if (i == j) continue;
			if (height[i] < height[j]) {
				if (weight[i] < weight[j]) {
					cnt++;
					
				}
			}
			
		}
		result[i] = cnt + 1;
	}
	for (int i = 0; i < testcase; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}