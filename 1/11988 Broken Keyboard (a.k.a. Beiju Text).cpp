#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
		while (cin >> s) {
			vector<char> v(s.begin(), s.end());
			list<char> l;
			auto e = l.begin();
			for (int i =0; i < v.size();++i) {
				if (v.at(i) == '[') {   
					e = l.begin();	// jump to the beginning of the text if char is [ (like Home button)
				}
				if (v.at(i) == ']') {
					e = l.end();   // jump to the end of the text if char is ] (like End button)
				}
				l.insert(e, v.at(i));
			}
			l.remove('[');	      // get rid of all [ ] signs
			l.remove(']');
			for (list<char>::const_iterator e = l.begin(); e != l.end(); ++e) {
				cout << *e;
			    }
			cout << endl;
	}
	return 0;
}
