#include<cstdio>
#include<iostream>

using namespace std;

void solve(int n) {
	if (n == 0) return;
	if (n % 2 == 0) {
		solve(-(n / 2));
		printf("0");
	}
	else {
		if (n > 0) solve(-(n / 2));
		else solve(-(n - 1) / 2);
		printf("1");
	}
}
int main() {
	int num;
	cin >> num;

	if (num == 0) printf("0");
	else solve(num);

	return 0;
}