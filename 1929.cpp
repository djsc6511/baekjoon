#include<cstdio>
#include<iostream>
#include<memory.h>
#define SIZE 1111111

using namespace std;

bool is_Prime[SIZE];

void eratos() {
	memset(is_Prime, true, SIZE);
	is_Prime[0] = is_Prime[1] = false;

	for (int i = 2; i*i < SIZE + 1; i++) {
		if (is_Prime[i])
			for (int j = i*i; j < SIZE; j += i)
				is_Prime[j] = false;
	}
}

int main() {
	eratos();
	int M, N;
	cin >> M >> N;
	
	for (int i = M; i <= N; i++) {
		if (is_Prime[i])
			cout << i << endl;
	}
	return 0;
}