#include <bits/stdc++.h>
using namespace std;

int main() {

	unordered_map<string,string> container;

	string s;
	string eng;
	string notEng;
	while (getline(cin,s)) {
		if (s == "")
			break;

		istringstream sinp (s);
		sinp >> eng >> notEng;
		container.emplace(notEng,eng);
	}

	while (cin >> s) {
		if (container.find(s) != container.end()) {
			cout << container[s] << endl;
		} else {
			cout << "eh" << endl;
		}
	}








	return 0;
}
