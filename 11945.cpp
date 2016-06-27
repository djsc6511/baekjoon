#include<cstdio>

using namespace std;

int main(void) {
	int N, M;
	char fish[11][11];
	char tmp[11][11];
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%c", &fish[i][j]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++){
			printf("%c", fish[i][j]);
		}
			

	}
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			if (fish[i][j] != fish[i][M - j - 1]) {
				tmp[i][j] = fish[i][M-j-1];
				fish[i][M - j - 1] = fish[i][j];
				fish[i][j] = tmp[i][j];
			}
				
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%c", fish[i][j]);
		
	}*/
	
	return 0;
}