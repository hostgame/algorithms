#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases; cin >> cases;
	for (int q = 0;q < cases;++q) {
		int subjects; cin >> subjects;

		unordered_map<string, int> container;
		string s_temp;
		int i_temp;
		for (int i = 0; i < subjects;++i) {
			cin >> s_temp >> i_temp;
			container.emplace(s_temp,i_temp);
		} 
		cin >> i_temp >> s_temp;
		
		if (container.find(s_temp) == container.end()) {
				cout << "Case " << q+1 <<": Do your own homework!" << endl; 
		} else {
				if (i_temp >= container[s_temp]) {
				cout << "Case " << q+1 <<": Yesss" << endl; 
				} else if (i_temp + 5 >= container[s_temp]) {
				cout << "Case " << q+1 <<": Late" << endl; 
				} else {
				cout << "Case " << q+1 <<": Do your own homework!" << endl; 
				}
		}
	}
	return 0;
}