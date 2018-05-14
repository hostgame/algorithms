#include <bits/stdc++.h>
using namespace std;

int main() {
	int days;
	multiset<int> container;
	while (cin >> days && days != 0) {
		long long result = 0;  // result should be in long long, because UVA gives too big numbers
		for (int q = 0; q < days; ++q) {

			int n;
			cin >> n;
			int temp;

			for (int i =0; i < n; ++i) {
				cin >> temp;
				container.emplace(temp);
			}
			
			auto beginIT = container.begin();
			auto endIT = container.end();         // in multiset end() returns an iterator 
			endIT--;						      // to the element next to the last one
												  // so we need --end() to get access to the last one element
			result += (*endIT - *beginIT);

			container.erase(beginIT);
			container.erase(endIT);
			
		}
		cout << result << endl;
		container.clear();
	}
	return 0;
}