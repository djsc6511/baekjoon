#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int j = 1;
	for (int i = 0; i <= num*num; i *= 6) {
		if (2 + i*j >= num) {
			cout << i << endl;
			break;
		}
		j++;
	}
	
	return 0;
}