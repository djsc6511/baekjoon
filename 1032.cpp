#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(void) {
	
	int n;
	string str,tmp;

	scanf("%d", &n);
	cin >> str;
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			if (str[j] == tmp[j])
				str[j] = tmp[j];
			else
				str[j] = '?';
		}
	}
	for (int i = 0; i < str.size(); i++) {
		printf("%c", str[i]);
	}
	
		
	
	return 0;
}