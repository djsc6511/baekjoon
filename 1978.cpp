#include<cstdio>
#include<iostream>
#define SIZE 1111

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
	int N;
	cin >> N;

	eratos();

	int count = 0;
	while (N--) {
		int num;
		cin >> num;

		if (is_Prime[num]) count++;
	}

	cout << count << endl;
	return 0;
}