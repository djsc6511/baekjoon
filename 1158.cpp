#include<cstdio>
#include<vector>
using namespace std;

vector<int> vt;
int main(void) {
	int n, m;
	int d;
	
	scanf("%d %d", &n, &m);
	d = m - 1;
	for (int i = 1; i <= n; i++)
		vt.push_back(i);
	printf("<");
	
	for (int i = 0; i < n; i++) {
		auto it = vt.begin();
		printf("%d", *(it+d));
		vt.erase(it + d);
		d += m - 1;
		if (vt.empty())break;
		d %= vt.size();
		printf(", ");
	}
	printf(">");
	return 0;
}