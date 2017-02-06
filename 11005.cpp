#include<cstdio>
#include<vector>

using namespace std;

vector<char> v;

int main() {
	int n, b;
	scanf("%d %d", &n, &b);

	while (n != 0) {
		int tmp = n % b;
		if (tmp >= 10 && tmp <= 35) {
			v.push_back(tmp - 10 + 'A');
		}
		else {
			v.push_back(tmp + '0');
		}
		n /= b;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%c", v[i]);
	}
	
	return 0;
}