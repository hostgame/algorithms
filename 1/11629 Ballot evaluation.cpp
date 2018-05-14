#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int parties;
	int guesses;

	cin >> parties >> guesses >> ws;

	unordered_map<string,int> container;

	string s_temp;
	double d_temp;
	int i_temp;
	
	for (int i = 0; i < parties; ++i) {
		cin >> s_temp >> d_temp;
		i_temp = d_temp * 10;                      // summarizing double values might cause inaccuracies, which we can't afford, therefore we get rid of number after . by multiplying value by 10
		container.emplace(s_temp,i_temp);
	}

	for (int i = 0; i < guesses;++i) {
		int sum = 0;
		while (cin >> s_temp) {
			if (s_temp == "<") {
				cin >> i_temp;					  // in guesses loop we have no inputs as double, so we can read as integer
				i_temp *= 10;					  // multiply by 10, to qualize with previous inputs
				if (sum < i_temp) {
					cout << "Guess #" << i+1 << " was correct." << endl;
					break;
				} else {
					cout << "Guess #" << i+1 << " was incorrect." << endl;
					break;
				}
			} else if (s_temp == ">") {
				cin >> i_temp;					 // do the same
				i_temp *= 10;
				if (sum > i_temp) {
					cout << "Guess #" << i+1 << " was correct." << endl;
					break;
				} else {
					cout << "Guess #" << i+1 << " was incorrect." << endl;
					break;
				}
			} else if (s_temp == ">=") {
				cin >> i_temp;					// do the same
				i_temp *= 10;
				if (sum >= i_temp) {
					cout << "Guess #" << i+1 << " was correct." << endl;
					break;
				} else {
					cout << "Guess #" << i+1 << " was incorrect." << endl;
					break;
				}
			} else if (s_temp == "<=") {
				cin >> i_temp;
				i_temp *= 10;					// do the same
				if (sum <= i_temp) {
					cout << "Guess #" << i+1 << " was correct." << endl;
					break;
				} else {
					cout << "Guess #" << i+1 << " was incorrect." << endl;
					break;
				}
			} else if (s_temp == "=") {
				cin >> i_temp;
				i_temp *= 10;					// do the same
				if (sum == i_temp) {
					cout << "Guess #" << i+1 << " was correct." << endl;
					break;
				} else {
					cout << "Guess #" << i+1 << " was incorrect." << endl;
					break;
				}
			} else if (s_temp != "+") {
			sum += container[s_temp];
			}
		}
	}
	return 0;
}