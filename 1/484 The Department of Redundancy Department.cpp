#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> my_pair;
int main() {
	int temp; 
	unordered_map<int,int> container;
	vector<int> s;
	while (cin >> temp) {
		if (container.find(temp) == container.end()) {		// if container does not have an element, insert it
			container.insert(my_pair(temp,1));
			s.push_back(temp);								// to keep initial order, insert numbers into vector
		} else {
			container[temp]++;								// if container does have a numer, increase its counter
		}
	}
	for (auto e : s) {										// print numbers in the initial order 
		auto it = container.find(e);
		cout << it->first << " " << it->second << endl;
	}
	return 0;	
}
