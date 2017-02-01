#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int GCD(int a, int b) {
	return b ? GCD(b, a%b) : a;
}

int main() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		int n;
		vector<int> num;
		int sum = 0;
		cin >> n;

		while (n--) {
			int tmp;
			cin >> tmp;
			num.push_back(tmp);
		}

		for (int i = 0; i < num.size() - 1; i++) {
			for (int j = 1 ; j < num.size(); j++) {
				if (i==j || i > j) continue;
				else sum += GCD(num[i], num[j]);
			}
		}

		cout << sum << endl;
	}
	
	return 0;
}