#include<cstdio>
#include<deque>
#include<string>
#include<iostream>

using namespace std;

int main() {
	int testcase;
	scanf("%d", &testcase); 


	deque<int> dq;

	while (testcase--) {
		string command;
		cin >> command;

		
		if (command.find("push_back") == 0) {
			int num;
			cin >> num;
			dq.push_back(num);
		}

		if (command.find("push_front") == 0) {
			int num;
			cin >> num;
			dq.push_front(num);
		}

		if (command == "pop_front") {
			if (!dq.empty()) {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
			else {
				printf("-1\n");
			}
		}

		if (command == "pop_back") {
			if (!dq.empty()) {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
			else {
				printf("-1\n");
			}
		}

		if (command == "size") {
			printf("%d\n", dq.size());
		}

		if (command == "empty") {
			if (!dq.empty()) {
				printf("0\n");
			}
			else {
				printf("1\n");
			}
		}

		if (command == "front") {
			if (!dq.empty()) {
				printf("%d\n", dq.front());
			}
			else {
				printf("-1\n");
			}
		}

		if (command == "back") {
			if (!dq.empty()) {
				printf("%d\n", dq.back());
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}