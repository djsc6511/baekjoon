#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int primes[9999];
int isVisited[9999];

int d[4] = { 1,10,100,1000 };
void primeArray() {
	int tmp[10000];
	for (int i = 2; i <= 9999; i++) {
		tmp[i] = i;
	}

	for (int i = 2; i <= 9999; i++) {
		if (tmp[i] == 0) continue;

		for (int j = i + i; j <= 9999; j += i) {
			tmp[j] = 0;
		}
	}

	for (int i = 1000; i <= 9999; i++) {
		if (tmp[i] != 0) {
			primes[i] = i;
			isVisited[i] = false;
		}
	}
}

bool isPrime(int n) {
	for (int i = 0; i < 9999; i++) {
		if (primes[i] == n) {
			return true;
		}
	}
	return false;
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	primeArray();

	while (testcase--) {
		int input, end;
		int result = -1;
		scanf("%d %d", &input, &end);

		pair<int, int> p;
		p = make_pair(input, 0);

		for (int i = 1000; i <= 9999; i++) {
			isVisited[i] = false;
		}

		queue<pair<int, int>> q;
		q.push(p);

		while (!q.empty()) {
			int digit[4];

			int from = q.front().first;
			int tmp = from;
			int count = q.front().second;

			if (from == end) {
				result = count;
				break;
			}

			for (int i = 0; i < 4; i++) {
				digit[i] = tmp % 10;
				tmp /= 10;
			}
			q.pop();

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int nd = from - digit[i] * d[i];
					nd += j*d[i];
					if (i == 0 && j == 0) continue;
					else {
						if (isPrime(nd) && !isVisited[nd]) {
							isVisited[nd] = true;
							q.push(make_pair(nd, count + 1));
						}
					}
				}
			}
		}
		if (result != -1) {
			printf("%d\n", result);
		}
		else {
			printf("impossible\n");
		}
	}
	return 0;
}