#include<stdio.h>
#include<vector>
using namespace std;

vector<int> n;

int main(void) {
	int N,n;
	int M; //���� ����
	int S, E;
	scanf("%d", &N); //(1~2000) //ĥ�ǿ� ���� ����
	for (int i = 0; i < N; i++) {
		scanf("%d", &n); //������ŭ ����(1~100000)
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &S, &E);
		if (S == E) {
			printf("1\n");
		}
		else if ((E - S) % 2 == 0) {
			while()
		}
	}

	
	return 0;
}