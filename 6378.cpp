#include<cstdio>

using namespace std;

int main() {
	while (true) {
		int num;
		
		scanf("%d", &num);

		if (num == 0) {
			break;
		}
		else {
			while (true) {
				int cipher[4];
				int sum = 0;

				for (int i = 0; i < 4; i++) {
					cipher[i] = num % 10;
					num /= 10;
				}

				for (int i = 0; i < 4; i++) {
					sum += cipher[i];
				}

				if (sum >= 10) {
					num = sum;
				}
				else {
					printf("%d\n", sum);
					break;
				}
			}
			
		}
	}
	return 0;
}