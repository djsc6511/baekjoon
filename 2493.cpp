#include<cstdio>
#include<stack>
#include<utility>
using namespace std;

stack<pair<int,int> >s;
int main(void) {
	
	int topcount;

	int h;
	scanf("%d", &topcount);

	for (int i = 1; i <= topcount; i++) {
		scanf("%d", &h);
		
		while (!s.empty()) {
			
			if (h < s.top().second) {
				
				printf("%d ", s.top().first);
				break;
			}
			s.pop();
		}
		if (s.empty()) printf("0 ");
		
		s.push(make_pair(i, h));
	}
		
	return 0;
}