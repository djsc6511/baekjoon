#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int tree[555][555] = { 0, };

int main(void) {
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d",&tree[i][j]);
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			tree[i][j] = max(tree[i - 1][j - 1], tree[i - 1][j]) + tree[i][j];
			result = max(result, tree[i][j]);
		}
	}
	printf("%d", result);
	
	return 0;
}