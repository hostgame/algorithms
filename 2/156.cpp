#include <bits/stdc++.h>
using namespace std;

int main() {
		
	multimap<string,string> container;

	string s_temp;
	string s_temp2;
	while (cin >> s_temp) {
		if (s_temp == "#")
			break;
		s_temp2 = s_temp;
		transform(s_temp2.begin(), s_temp2.end(), s_temp2.begin(), ::tolower);
		sort(s_temp2.begin(),s_temp2.end());
		container.emplace(s_temp2,s_temp);
	}
	
	map<string,int> m;
	for (auto e : container) {
		auto ip = container.equal_range(e.first);
		if (ip.first != ip.second) {
		m[ip.first->first]++;
		}
	}
	

	set<string> s;
	for (auto e : m) {
		if (e.second == 1) {
			for (auto x : container) {
				if (x.first == e.first) {
				
					s.insert(x.second);
				}
			}
		}
	}

	for (auto e : s) {
		cout << e << endl;
	}

	return 0;
}
