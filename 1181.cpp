#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<pair<int, string>> dic;

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		string s;
		cin >> s;
		
		pair<int,string> p = make_pair(s.length(), s);
		if (find(dic.begin(), dic.end(), p) != dic.end() && !dic.empty()) {
			continue;
		}
		else {
			dic.push_back(p);
		}
	}

	sort(dic.begin(), dic.end());

	for (int i = 0; i < dic.size(); i++) {
		cout << dic[i].second << endl;
	}
	return 0;
}