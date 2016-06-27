#include<stdio.h>
#include<vector>
using namespace std;
vector<vector<char>> star(100,vector<char>(100,0));
int main(void) {
	
	
	int count;
	scanf("%d", &count);

	for (int i = 0; i <count; i++){
		for (int j = 0; j <count; j++) {
			if (i > j)
				star[i][j] = ' ';
			else
				star[i][j] = '*';
			printf("%c", star[i][j]);
		}
		printf("\n");
	}
		
			
	
		
	return 0;
}