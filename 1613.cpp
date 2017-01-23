#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 987654321

using namespace std;

int map[444][444];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < k; i++) {
		int be, af;
		cin >> be >> af;

		map[be][af] = 1;

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					map[i][j] = min(map[i][j], map[i][k] + map[k][i]);
				}
			}
		}
	}

	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int b, a;
		cin >> b >> a;

		if (map[b][a] != INF) cout << -1 << "\n";
		else if (map[a][b] != INF) cout << 1 << "\n";
		else cout << 0 << "\n";;
	}
	
	return 0;
}