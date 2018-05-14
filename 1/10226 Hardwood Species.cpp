#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n >> ws;

	for (int i = 0; i < n;++i) {
	
		map<string,int> container;
		int sum = 0;                       // sum stores amount of all the trees we have, usefull for counting percentage
		string temp;

		while (getline(cin, temp)) {
			if (temp == "") {
				break;
			}
			if (container.find(temp) == container.end()) {
				container[temp] = 1;
			} else {
				container[temp]++;
			}
			sum++;
		}

		for (auto e : container) {
			double t = (double)e.second / (double)sum * (double)100;    // count percentage
			cout << fixed << setprecision(4) << e.first << " " << t << endl;
		}
		if (i != n-1)
		cout << endl;
	}

	return 0;
}