#include<cstdio>
#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	int result = 0;

	cin >> a >> b >> c;

	result = (a + b) % c;
	cout << result << endl;
	

	result = (a % c + b % c) % c;
	cout << result << endl;

	result = (a * b) % c;
	cout << result << endl;

	result = (a % c * b % c) % c;
	cout << result << endl;
	return 0;
}