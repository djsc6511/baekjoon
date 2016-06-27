#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int testcase;
	string K;
	int tmp;

	scanf("%d", &testcase);
	while (testcase--) {
		cin >> K;
		//printf("%c", K[(K.size() - 1)]);
		if (K[(K.size() - 1)] == '0'|| K[(K.size() - 1)] == '2'|| K[(K.size() - 1)] == '4'
			|| K[(K.size() - 1)] == '6'|| K[(K.size() - 1)] == '8')
			tmp = 0;
		else
			tmp = 1;
		//printf("%d\n", tmp);
		if (tmp == 0)
			printf("even\n");
		else
			printf("odd\n");
	}

	
	return 0;
}