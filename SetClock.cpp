#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 987654321;
const int SWITCHES = 10;
const int CLOCKS = 16;

const char linked[SWITCHES][CLOCKS+1] = {
	"xxx0000000000000",
	"000x000x0x0x0000",
	"0000x00000x000xx",
	"x000xxxx00000000",
	"000000xxx0x0x000",
	"x0x00000000000xx",
	"000x0000000000xx",
	"0000xx0x000000xx",
	"0xxxxx0000000000",
	"000xxx000x000x00"
};

bool areAligned(const vector<int>& clocks);

void push(vector<int>& clocks, int swtch) {
	for (int i = 0; i < CLOCKS; i++) {
		if (linked[swtch][i] == 'x') {
			clocks[i] += 3;
			if (clocks[i] == 15) {
				clocks[i] = 3;
			}
		}
	}
}

int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return ret;
}

int main() {
	int testcase;
	
	scanf("%d", &testcase);

	/*
		12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
		12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
	*/

	while (testcase--) {
		vector<int> clocks;
		for (int i = 0; i < CLOCKS; i++) {
			int tmp;
			scanf("%d", &tmp);
			clocks.push_back(tmp);
		}

		printf("%d\n", solve(clocks, 0));
	}
	
	return 0;
}

bool areAligned(const vector<int>& clocks) {
	bool ok = true;
	for (int i = 0; i < clocks.size(); i++) {
		if (clocks[i] == 12) {
			ok = true;
		}
		else {
			ok = false;
			break;
		}
	}
	return ok;
}