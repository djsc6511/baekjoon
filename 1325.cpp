#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
int x, y;
int computer[11111] = { 0, };
vector<pair<int, int>> v;
vector<int> vc;

int main() {
	scanf("%d %d", &N, &M);

	while (M--) {
		scanf("%d %d", &x, &y);
		computer[x] = computer[x] - 1;
		computer[y] = computer[y] + 1;
	}

	pair<int, int> p;

	for (int i = 1; i <= N; i++) {
		v.push_back(make_pair(computer[i], i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		
	}
	for (int i = v.size()-1; i >=0; i--) {
		vc.push_back(v[i].second);
		
		if (i != 0) {
			if (v[i].first != v[i - 1].first) {

				break;
			}
		}
			
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < vc.size(); i++) {
		printf("%d ", vc[i]);
	}
	
	return 0;
}