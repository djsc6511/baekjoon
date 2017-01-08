#include<cstdio>
#include<vector>

using namespace std;

vector<int> numbers;

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int number;
		scanf("%d", &number);
		numbers.push_back(number);
	}

	int num;
	int count = 0;
	scanf("%d", &num);

	for (int i = 0; i < numbers.size(); i++) {
		if (num == numbers[i]) {	
			count++;
		}
	}

	printf("%d", count);
	return 0;
}