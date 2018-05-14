#include <bits/stdc++.h>
using namespace std;

int main() {
	typedef pair<int, int> my_pair;   // define type pair <int,int>
	int n; 
	int t;
	cin >> n;
	set<my_pair> container;
	for (int i =0; i < n;++i) {				// read numbers and insert them to the set of pairs<int, int>
		cin >> t;							// set is sorted by first value in pair, so it keeps required order
		my_pair p(i,t);
		container.insert(p);
	}
	     int i = 1;
	for (auto e : container) {
		t = e.second;
		int sum = 0;
		do {
			while (t > 0) {								// our input value can be < 10, so while loop will not be called at all
				sum += (t % 10) * (t % 10);				// therefore we use do while
				t /= 10;
			}
			t = sum;
			sum = 0;
		} while (t >= 10);
	
	   if (t == 1) {
		cout << "Case #" << i << ": " << e.second << " is " <<  "a Happy number." << endl;
	}  else { 
		cout << "Case #" << i << ": " << e.second << " is " <<  "an Unhappy number." << endl;
	}
	++i;
	}
	return 0;
}