#include<cstdio>

using namespace std;

int map[16];
int N;
int count = 0;

int abs(int a, int b) {
	if (a >= b)
		return a - b;
	else
		return b - a;
}

bool check(int row) {	
	for (int i = 0; i < row; i++) {
		if (map[row] == map[i] || row - i == abs(map[row], map[i])) {
			return false;
		}
		
	}
	return true;
}

void Nqueen(int row) {
	
	if (row == N - 1) {
		count++;
		
		return;
	}
	for (int i = 0; i < N; i++) {
		
		map[row+1] = i;
		//printf("%d ", map[row + 1]);
		if (check(row+1)) {
			Nqueen(row+1);
		}
	}
	printf("\n");
}

int main(void) {
	scanf("%d", &N);

	Nqueen(-1);
	
	printf("%d", count);
	
	return 0;
}