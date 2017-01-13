#include<cstdio>
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	string stick;
	cin >> stick;

	stack<char> sticks;
	int piece = 0;

	for (int i = 0; i < stick.length(); i++) {
		if (stick[i] == '(') {
			sticks.push(stick[i]);
		} else {
			sticks.pop();
			if (stick[i - 1] == '(') {
				piece += sticks.size();
			}
			else {
				piece += 1;
			}
		}
	}

	printf("%d", piece);
	return 0;
}