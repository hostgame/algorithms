#include <bits/stdc++.h>
using namespace std;
int main() {
	int input1, input2, temp;
	while (cin >> input1 >> input2) {
		int result = 0;
		if (input1 == 0 && input2 == 0) return 0;
		unordered_set<int> container;
		for (int i = 0; i < input1;++i) {				// read all first numbers into container				
			cin >> temp;
			container.insert(temp);
		}
		for (int i = 0;i < input2;++i) {				// read all second numbers
			cin >> temp;
			if (container.find(temp) != container.end()) {	// if number exists in container, increase result  
				++result;
			}
		}
		cout << result << endl;
	}
	return 0;	
}
