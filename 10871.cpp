#include<stdio.h>
#include<vector>
using namespace std;
vector<int> num;
int main(void) {
	num.resize(100000);

	int N, X;
	int random;
	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; i++) {
		scanf("%d", &random);
		num[i] = random;
	}
	for (int i = 0; i < N; i++) {
		if(num[i]<X)
			printf("%d ", num[i]);
	}
	return 0;
}