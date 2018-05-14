#include <bits/stdc++.h>
using namespace std;

int main() {

	set<string> container;
	set<string> v;
	string temp;
	while (cin >> temp) {
		container.insert(temp);
	}

	for (auto e : container) {			// loop checks every word in the set
		for (int i =0; i < e.length(); ++i) {				
			if (container.find(e.substr(0, i)) != container.end() &&   // every word is divided in all possible ways in 2 parts
				container.find(e.substr(i,e.length()-1)) != container.end() ) {   // if the set contains both of them, adds the word to the result
				v.insert(e);
			}
		}

			
	}

	for (auto e : v) {
		cout << e << endl;
	}
	return 0;
}