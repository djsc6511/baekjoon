#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> s;
vector<int> c;


int main(void) {
	s.resize(511111);
	c.resize(511111);

	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &s[i]);
	}
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &c[i]);
	}
	
	sort(s.begin(), s.begin()+N);
	
	for (int i = 0; i < M; i++) {
		int low = 0;
		int high = N-1;
		int mid;

		while (low <= high) {
			mid = (low + high) / 2;

			if (s[mid] == c[i]) {
				printf("1 ");
				break;
			}
			else if (s[mid] < c[i]) {
				low = mid + 1;
			}
			else
				high = mid - 1;

			if (low > high) {
				printf("0 ");
				break;
			}
				
		}
	}
	return 0;
}