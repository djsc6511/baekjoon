#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string num;
	vector<int> oct;
	cin >> num;

	int tmp = num.size() % 3;
	int j = num.size() - 1;
	for (int i = 0; i < num.size() / 3; i++) {
		int result = 0;
		result += (num[j] - '0');
		result += (num[j - 1] - '0') * 2;
		result += (num[j - 2] - '0') * 4;
		j -= 3;
		oct.push_back(result);
	}

	if (tmp == 1) {
		oct.push_back(num[0] - '0');
	}
	else if (tmp == 2) {
		oct.push_back((num[1] - '0') + (num[0] - '0') * 2);
	}

	for (int i = oct.size()-1; i >=0; i--) {
		printf("%d", oct[i]);
	}
	return 0;
}