#include <bits/stdc++.h>
using namespace std;

int main() {
	int slogans; cin >> slogans >> ws;
	
	unordered_map<string,string> container;

	string s_temp;
	string s_temp2;

	for (int i = 0; i < slogans;++i) {
		getline(cin, s_temp);
		getline(cin,s_temp2);
		container.emplace(s_temp,s_temp2);
	}

	int outs; cin >> outs >> ws;
	for (int i = 0; i < outs;++i) {
		getline(cin,s_temp);
		cout << container[s_temp] << endl;
	}
	return 0;
}