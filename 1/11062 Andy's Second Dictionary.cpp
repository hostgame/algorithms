#include <bits/stdc++.h>
using namespace std;

int main() {
	string temp;
	string s;
	set<string> container;

	while (getline(cin, temp)) {  				    // all the lines are collected into a single string
		if (temp[temp.length()-1] != '-') {         // if a line ends normally, add space to the end of it 
			temp += " ";
		} else if (temp[temp.length()-1] == '-') {
			temp = temp.substr(0, temp.size()-1);   // if line ends with -, remove it and add no space
		}
		s += temp;
	}
	
	transform(s.begin(), s.end(), s.begin(), ::tolower); // all characters should be in lower case

	string t;

	for (int i = 0; i < s.length();++i) {
					if (isalpha(s[i]) || s[i] == '-') {  // if character is a letter or -, it is added to the word
						t += s[i];
					} else {
							if (t.size()>0) {      // once we reach any non alpha character and the size of temporary word is > 0, it is added to the set
							container.insert(t);
							t = "";                // temporary word is set to zero
						    }
					
				}
			}

		for (auto e: container) {
		cout << e << endl;
		}

	return 0;
}