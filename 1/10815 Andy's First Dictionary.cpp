#include <bits/stdc++.h>

using namespace std;

	int main() {
	string s;

	set<string> container;
	while (getline(cin, s)) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);  // all characters should be in lower case
		string t;
		for (int i = 0; i < s.length();++i) {
				if (isalpha(s[i])) {   // if character is a letter, it is added to the word
					t += s[i];
						if (i == s.length()-1) {   // if we reach the end of line, and our temporary word is not empty, add to the set
							if (t.size()>0) {
							container.insert(t);
							t = "";       		   // temporary word is set to zero
							}
					    }

				} else {
				
						if (t.size()>0) {      // once we reach any non alpha character and the size of temporary word is > 0, it is added to the set
						container.insert(t);
						t = "";
					    }
				
			}
		}

	}


	for (auto e: container) {
		cout << e << endl;
	}
	return 0;
	}