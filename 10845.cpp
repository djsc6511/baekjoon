#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

struct {
	vector<int> queue;
	int front = -1;
	int rear = -1;
}q;

void push(int num) {
	q.rear = q.rear + 1;
	q.queue[q.rear] = num;
	//printf("%d\n", q.queue[q.rear]);
}

void empty() {
	if (q.front == q.rear)
		printf("1\n");
	else
		printf("0\n");
		
}

void pop() {
	if (q.front == q.rear)
		printf("-1\n");
	else {
		q.front = q.front + 1;
		printf("%d\n", q.queue[q.front]);
	}
		
}

void size() {
	int size;
	size = q.rear - q.front;
	printf("%d\n", size);
}

void front() {
	if (q.front == q.rear)
		printf("-1\n");
	else
		printf("%d\n", q.queue[q.front + 1]);
}

void back() {
	if (q.front == q.rear)
		printf("-1\n");
	else
		printf("%d\n", q.queue[q.rear]);
}
int main(void) {
	char operation[20];
	q.queue.resize(10000);
	int num,count;
	scanf("%d",&count);
	for (int i = 0; i < count; i++) {
		scanf("%s", &operation);
		
		if (!strcmp(operation, "push")) {
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp(operation, "front"))
			front();
		else if (!strcmp(operation, "back"))
			back();
		else if (!strcmp(operation, "empty"))
			empty();
		else if (!strcmp(operation, "size"))
			size();
		else if (!strcmp(operation, "pop"))
			pop();

	}
	
	return 0;
}