#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> numbers;

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int num;
		scanf("%d", &num);
		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.size(); i++) {
		printf("%d\n", numbers[i]);
	}
	return 0;
}