#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

struct {
	vector<int> stack;
	int top = -1;
}s;

void push(int num) {
	s.top = s.top + 1;
	s.stack[s.top] = num;
}

void pop() {
	if (s.top == -1)
		printf("-1\n");
	else {
		printf("%d\n", s.stack[s.top]);
		s.top = s.top - 1;
	}
}

void size() {
	int size = 0;
	size = s.top + 1;
	printf("%d\n", size);
}

void empty() {
	if (s.top == -1)
		printf("1\n");
	else
		printf("0\n");
}

void top() {
	if (s.top == -1)
		printf("-1\n");
	else
		printf("%d\n", s.stack[s.top]);
}
int main(void) {
	char operation[20];
	s.stack.resize(10000);
	int num, count;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%s", &operation);

		if (!strcmp(operation, "push")) {
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp(operation, "pop"))
			pop();
		else if (!strcmp(operation, "size"))
			size();
		else if (!strcmp(operation, "empty"))
			empty();
		else if (!strcmp(operation, "top"))
			top();

	}
	return 0;
}