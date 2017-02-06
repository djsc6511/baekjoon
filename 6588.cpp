#include<cstdio>
#include<iostream>
#include<vector>
#include<memory.h>
#define SIZE 1000001

using namespace std;

bool is_Prime[SIZE];

void eratos() {
	memset(is_Prime, true, sizeof(is_Prime));

	is_Prime[0] = is_Prime[1] = false;
	for (int i = 2; i*i < SIZE; i++) {
		if (is_Prime[i])
			for (int j = i*i; j < SIZE; j += i)
				is_Prime[j] = false;
	}
}

int main() {
	eratos();

	while (true) {
		int n;
		scanf("%d", &n);
		int result = 0;
		if (n == 0) return 0;
		else {
			for (int i = 2; i <= n; i++) {
				if (is_Prime[i] && is_Prime[n - i]) {
					result = 1;
					printf("%d = %d + %d\n", n, i, n - i);
					break;
				}
			}
		}

		if (result == 0) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
	return 0;
}