#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a;
vector<int> b;

int main(void) {
	
	int N,mid;
	scanf("%d", &N);
	a.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	
	int M;
	scanf("%d", &M);
	b.resize(M);
	for (int i = 0; i < M; i++)
		scanf("%d", &b[i]);

	sort(a.begin(), a.end());

	
	for (int i = 0; i < M; i++) {
		int low = 0;
		int high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;

			if (a[mid] == b[i]) {
				printf("1\n");
				
				break;
			}

			else if (a[mid] < b[i])
				low = mid + 1;
			else
				high = mid - 1;
		}
		if (a[mid] != b[i])
			printf("0\n");
		
	}
	

	
	return 0;
}