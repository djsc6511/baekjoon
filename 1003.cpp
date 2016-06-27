#include<stdio.h>
#include<string.h>

int arr[101][2];

int recur(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 0;
	}
	int &ret0 = arr[n][0];
	if (ret0 != -1) {
		return ret0;
	}
	ret0 = recur(n - 1) + recur(n - 2);
	return ret0;
}

int recur1(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	int &ret1 = arr[n][1];
	if (ret1 != -1) {
		return ret1;
	}

	
	ret1= recur1(n - 1) + recur1(n - 2);
	return ret1;
}


int main() {
	int n;
	int num;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {

		scanf("%d", &num);

		for (int k = 0; k < 101; k++) {
			for (int j = 0; j < 2; j++) {
				arr[k][j] = -1;
			}
		}

	
		printf("%d %d\n", recur(num), recur1(num));
	}


}