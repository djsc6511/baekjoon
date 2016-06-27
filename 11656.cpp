#include<stdio.h>
#include<stack>
#include<vector>
#include<string>
using namespace std;

string str="";
vector<string> tmp;
//vector<char> tmp;
//vector<string> s;

int main(void) {
	tmp.resize(1000000);
	scanf("%s", &str);
	
	int j = 0;
	int len = str.length();
	printf("±æÀÌ=%d", len);
	for (int i = len - 1; i >= 0; i--) {
		
		tmp[j] = str.substr(i, len - 1);
		printf("%s\n", tmp[j]);
		j++;
	}
	

/*
tmp.resize(10000);
s.resize(100000);
int i = 0;
int j = 0;

scanf("%s", str);

int len = strlen(str);

stack<char> st;

while (len--) {
st.push(str[i]);
i++;
}
while (!st.empty()) {
if (j == 0)
s[j] = st.top();
else
s[j] = st.top()+s[j - 1];
printf("%s ", s[j]);
st.pop();
j++;
}
*/
	
	
	return 0;
}