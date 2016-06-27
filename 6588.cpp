#include<stdio.h>
#include<vector>

using namespace std;
vector<int> prime;

int main(void){
	prime.resize(100000,0);
	int num;
	scanf("%d", &num);

	for (int i = 2; i*i < 1000000; i++) {
		for (int j = i + i; j < 1000000; j += i) {

		}
	}
	return 0;
}