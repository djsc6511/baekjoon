#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;

char str[1000000];

int main(void) {
	
	int cnt;
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%s", str);

		int len = strlen(str);
		stack<char> t1, t2;
		for (int j = 0; j < len; j++) {
			char c = str[j];

			if (c == '<') {
				if (!t1.empty()) {
					t2.push(t1.top());
					t1.pop();
				}
			}
			else if (c == '>') {
				if (!t2.empty()) {
					t1.push(t2.top());
					t2.pop();
				}
			}
			else if (c == '-') {
				if (!t1.empty()) {
					t1.pop();
				}
			}
			else
				t1.push(c);
			
		}
		while (!t1.empty()) {
			t2.push(t1.top());
			t1.pop();
		}

		while (!t2.empty()) {
			printf("%c", t2.top());
			t2.pop();
		}
		printf("\n");
	}
	return 0;
	

}