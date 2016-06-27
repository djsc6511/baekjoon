#include<cstdio>
#include<vector>
using namespace std;

vector<int> n;
vector<int> sum;
vector<bool> selected;
int num;
int ans;

int main(void) {
	n.resize(50001,0);
	sum.resize(50001);
	selected.resize(65555);

	int i = 1;
	while ((i*(i + 1)) / 2<1000) {
		n[i - 1] = (i*(i + 1)) / 2;
		i++;
	}
	int testcase;
	scanf("%d", &testcase);

	for (int l = 0; l < testcase; l++) {
		scanf("%d", &num);
		
		for (int j = 0; j < i-1; j++) {
			for (int k = 0; k < i-1; k++) {
				for (int m = 0; m < i-1; m++) {
					ans = 0;
					ans = n[j] + n[k] + n[m];
					
					if (ans == num) {
						
						break;
					}

				}
				if (ans == num) {

					break;
				}
			}
			if (ans == num) {

				break;
			}
		}
		
		if (ans == num)
			printf("1\n");
		else
			printf("0\n");
	}
	

	
	
	return 0;
}