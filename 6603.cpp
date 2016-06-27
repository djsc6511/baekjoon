#include<cstdio>

using namespace std;

int lotto[10];
int tmp[30];
int exit;

void check(int idx,int count) {
	if (count == 6) {
		for (int i = 0; i < count; i++)
			printf("%d ", lotto[i]);
		printf("\n");
		return;
	}
	if (idx == exit)
		return;

	lotto[count] = tmp[idx];
	check(idx + 1, count + 1);
	check(idx + 1, count);
	
	

}
int main(void) {
	scanf("%d", &exit);
	while (exit--) {
		if (exit == 0)
			break;

		for (int i = 0; i < exit; i++)
			scanf("%d", &tmp[i]);

		check(0, 0);
		printf("\n");
	}
	return 0;
}