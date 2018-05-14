#include <bits/stdc++.h>
using namespace std;

int main() {

	int cases; 
	cin >> cases;
	while (cases--) {
		
		int snowflakes;
		cin >> snowflakes;
		
		unordered_map<int,int> container;
		
		int current = 0;
		int prev = 0;											// for previous not unique element
		int counter = 0;										
		int result = 0;

		for (int i = 1; i <= snowflakes;++i) {     				// we track lenght of our map with i, so we have to start from 1
			cin >> current;
			if (container.find(current) == container.end()) {
				container.emplace(current,1);					// if map does not contain new element, insert it
			} else {
				prev = max(prev,container[current]);			// if it does, set previous length to maximum among previous length and counter of current element
				counter = i-(prev+1);							// set counter to difference of current length of our map and previous length+1
			}
			counter++;											// increase counter for current step	
			container[current] = i;								// store current length of the map in map[current]
			result = max(result,counter);						// set result to maximum among previous maximum and current counter
		}
		cout << result << endl;
	}
	return 0;
}