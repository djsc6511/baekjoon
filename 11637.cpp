#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

vector<pair<int,int> > vote;

void print(vector<pair<int,int>> num) {
	int sum = 0;
	int tmp = 0;
	for (int i = 0; i < sizeof(num); i++) {
		sum += num[i].first;
		num[i].second = i + 1;
	}
	tmp = sum/2;
	sort(num.begin(),num.end());
	reverse(num.begin(), num.end());
	if (num[0].first == num[1].first)
		printf("no winner\n");
	else {
		if (tmp < num[0].first)
			printf("majority winner %d\n", num[0].second);
		else
			printf("minority winner %d\n", num[0].second);
	}
	
}
int main(void) {
	vote.resize(54321);
	int testcase, num;
	scanf("%d", &testcase);
	
	for (int i = 0; i < testcase; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &vote[j]);
		}
		print(vote);
	}

	return 0;
}