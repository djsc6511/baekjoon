#include<cstdio>
#include<vector>

using namespace std;

vector<int> num;
int main(void) {
	num.resize(1000001);
	int a, b;
	int k = 0;
	int result = 0;
	scanf("%d %d", &a, &b);

	for (int i = 1; i <= 1000; i++) {
		for (int j = i; j >0; j--) {
			num[k] = i;
			//printf("%d¹øÂ°¼ö%d\n", k, num[k]);
			k++;
			
		}
		
	}
	for (int i = a-1; i < b; i++) {
		result += num[i];
	}
	printf("%d",result);
	return 0;
}