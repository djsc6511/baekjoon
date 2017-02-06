#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
int main() {
	string n;
	cin >> n;

	int len = n.size();

	int n0 = n[0] - '0';
	for (int j = 0; j < 3; j++) {
		if (n0 != 0) {
			int tmp = n0 % 2;
			v.push_back(tmp);
			n0 /= 2;
		}
	}
	
	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%d", v[i]);
	}
	v.clear();
	for (int i = 1; i < len; i++) {
		int ni = n[i] - '0';
		for (int j = 0; j < 3; j++) {

			if (ni == 0) {
				v.push_back(0);
			}
			else {
				int tmp = ni % 2;
				v.push_back(tmp);
				ni /= 2;
			}
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			printf("%d", v[i]);
		}
		v.clear();
	}

	
	return 0;
}