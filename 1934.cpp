#include<cstdio>
#include<iostream>

using namespace std;

int GCD(int a, int b) {
	return b ? GCD(b, a%b) : a;
}
int main() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		int a, b;
		cin >> a >> b;

		int max = GCD(a, b);
		int min = (a / max)*(b / max)*max;
		cout << min << endl;
	}
	return 0;
}