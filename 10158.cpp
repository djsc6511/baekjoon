#include<cstdio>

using namespace std;

int main(void) {
	unsigned int w, h, p, q;
	unsigned long t;
	scanf("%d %d", &w, &h);
	scanf("%d %d", &p, &q);
	scanf("%d", &t);
	int x = 1;
	int y = 1;

	while (t--) {
		if (p == w || p == 0)
			x = -x;

		if (q == h || q == 0)
			y = -y;

		p += x;
		q += y;
	}

	printf("%d %d", p, q);
	return 0;
}