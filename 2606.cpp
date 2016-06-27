#include<cstdio>

using namespace std;
int com[111][111] = { 0, };
bool visited[111];
int count=0;
int connect;
int com_num;
void dfs(int n) {
	visited[n] = true;
	
	for (int i = 1; i <= com_num; i++) {
		if (!visited[i] && com[n][i]==1) {
			dfs(i);
			count++;
		}
	}
	
}
int main(void) {
	
	
	int num1, num2;
	scanf("%d", &com_num);
	scanf("%d", &connect);

	for (int i = 1; i <= connect; i++) {
		scanf("%d %d", &num1, &num2);
		com[num1][num2] = 1;
		com[num2][num1] = 1;
	}
	dfs(1);
	printf("%d", count);
	return 0;
}