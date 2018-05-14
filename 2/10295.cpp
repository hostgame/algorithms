#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int dictionary;
	int descriptions;

	cin >> dictionary >> descriptions;

	map<string,int> container;
	string s_temp;
	int i_temp;
	for (int i = 0; i < dictionary;++i) {
		cin >> s_temp >> i_temp;
		container.emplace(s_temp,i_temp);
	}

	int sum = 0;

	while (cin >> s_temp) {
		if (s_temp == ".") {
			cout << sum << endl;
			sum = 0;
			continue;
		}
		sum += container[s_temp];
	}
	return 0;
}
