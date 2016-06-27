#include <stdio.h>

int R, C; //��, ���� ũ��
int maze[11][11];

/*
�̷ΰ� �־�����.
��δ� 1, ���� 2�� �Է��� ���´�.
������ ���� 3�� ǥ���Ѵ�.
�� �ܰ踶�� �̷��� ���¸� 2���� �迭�� ���·� ����Ѵ�.

7 7
1 1 1 1 1 1 2
2 2 1 2 2 2 1
1 1 1 1 2 2 1
2 1 2 2 2 2 1
1 1 2 1 1 1 1
1 2 2 1 2 2 1
1 1 1 1 1 2 1

*/

//�� �� �� ��
int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { 1, 0, -1, 0 };

void print_maze() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void func(int x, int y) {
	//�������
	if (x == R && y == C) {
		printf("FINISH!\n");
		return;
	}

	int nx, ny;
	for (int i = 0; i<4; i++) {
		nx = x + x_move[i];
		ny = y + y_move[i];

		//������ 4���� ĭ�� �� �� �ִ� ĭ�� ��
		if (maze[nx][ny] == 1) {
			maze[nx][ny] = 3; //������ ���̱� ������ 3���� ǥ��
			print_maze(); //���
			func(nx, ny); //�Լ� ���ȣ��
			maze[nx][ny] = 1; //Back Track!!!!! �̷ο��� �ٽ� �ǵ��� ���� = �ٽ� ���� �����鼭 3���� �湮 ǥ�ø� �ߴ� ���� 1�� ���� ���� ���������
			//print_maze();
		}
	}
}

int main(void) {

	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &maze[i][j]);
		}
	}
	printf("\n");

	maze[1][1] = 3;
	func(1, 1);

	return 0;
}

