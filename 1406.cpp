#include<cstdio>
#include<string>
#include<iostream>
#include<stack>

using namespace std;

stack<char> st;
stack<char> tmp;

int main() {
	string init;
	cin >> init;

	for (int i = 0; i < init.length(); i++) {
		st.push(init[i]);
	}

	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		char command;
		cin >> command;

		if (command == 'P') {
			char c;
			cin >> c;
			st.push(c);
		}

		if (!st.empty() && command == 'L') {
			tmp.push(st.top());
			st.pop();
		}

		if (!tmp.empty() && command == 'D') {
			st.push(tmp.top());
			tmp.pop();
		}

		if (!st.empty() && command == 'B') {
			st.pop();
		}
	}

	while (!st.empty()) {
		tmp.push(st.top());
		st.pop();
	}

	while (!tmp.empty()) {
		cout << tmp.top();
		tmp.pop();
	}
	return 0;
}