#include<cstdio>
#include<string.h>
#include<math.h>

using namespace std;

int main() {
	char n[50];
	int b;

	scanf("%s %d", n, &b);
	int result = 0;
	int len = strlen(n);
	for (int i = 0; i < len; i++) {
		if (n[len - i - 1] >= 'A' && n[len - i - 1] <= 'Z') {
			result += (n[len - i - 1] - 'A' + 10) * pow(b, i);
		}
		else {
			result += (n[len - i - 1] - '0') * pow(b, i);
		}
	}
	
	printf("%d", result);
	return 0;
}