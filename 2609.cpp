#include<cstdio>
#include<iostream>

using namespace std;

int GCD(int a, int b) {
	return b ? GCD(b, a%b) : a;
}
int main() {
	int a, b;
	cin >> a >> b;

	int max = GCD(a, b);
	cout << max << endl;
	int min = (a / max)*(b / max)*max;
	cout << min << endl;
	return 0;
}