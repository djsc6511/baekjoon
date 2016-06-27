#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> cost;
vector<int>::iterator it;
int main(void) {
	cost.resize(100001);
	int n, boundry;
	unsigned long long max,tmp=0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i]);
		tmp += cost[i];
	}
	scanf("%d", &max);
	sort(cost.begin(), cost.end());
	it = cost.end();
	if (tmp < max) {
		printf("%d", *it);
	}
	return 0;
}