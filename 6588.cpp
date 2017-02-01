#include<cstdio>
#include<iostream>
#include<vector>
#define SIZE 1000001
using namespace std;

bool is_Prime[SIZE];
vector<int> prime;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void eratos() {
	memset(is_Prime, true, sizeof(is_Prime));

	is_Prime[0] = is_Prime[1] = false;
	for (int i = 2; i*i < SIZE + 1; i++) {
		if (is_Prime[i]) {
			for (int j = i*i; j < SIZE + 1; j += i) {
				is_Prime[j] = false;
			}
		}
			
	}
	return;
}

int main() {
	eratos();

	while (true) {
		int n;
		cin >> n;
		
		int result = 0;
		int check = 0;
		int a, b;
		for (int i = 0; i < SIZE; i++) {
			if (is_Prime[i])
				prime.push_back(i);
		}
		if (n == 0) break;
		else {
			for (int i = 0; i < prime.size(); i++) {
				for (int j = i; j < prime.size(); j++) {
					if (prime[i] + prime[j] == n) {
						if (prime[j] - prime[i] > result) {
							result = prime[j] - prime[i];
							a = i;
							b = j;
						}
						check++;
					}
				}
			}
		}
		if (check == 0) {
			cout << "Goldbach's conjecture is wrong." << endl;
		}
		else {
			printf("%d = %d + %d", result, a, b);
		}
		
	}
	return 0;
}