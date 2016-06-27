#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;

char a[100],b[100];
char map[100][100];
bool check;

int main(void) {
	scanf("%s %s", a, b);
	int lena = strlen(a);
	int lenb = strlen(b);
	int tmpi, tmpj;
	for (int i = 0; i < lenb; i++) {
		for (int j = 0; j < lena; j++) {
			map[i][j] = '.';
		}
	}
	
	for (int i = 0; i < lena; i++) {
		check = false;
		for (int j = 0; j < lenb; j++) {
			if (a[i] == b[j]) {
				tmpi = i;
				tmpj = j;
				check = true;
				//printf("%d %d", tmpi, tmpj);
				break;
			}
		}
		if(check) break;
	}
	for (int i = 0; i < lena; i++) {
		map[tmpj][i] = a[i];
	}
	for (int i = 0; i < lenb; i++) {
		map[i][tmpi] = b[i];
	}
	for (int i = 0; i < lenb; i++) {
		for (int j = 0; j < lena; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}