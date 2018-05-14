#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> my_pair;
int main() {
		int cases;
		cin >> cases;
		while (cases--) {
		int elementsInFirstList;
		int elementsInSecondList;
		int temp;

		cin >> elementsInFirstList;
		cin >> elementsInSecondList;
	
		unordered_map<int,int> list1;
		unordered_map<int,int> list2;


		for (int i = 0; i < elementsInFirstList;++i) {								
			cin >> temp;															
			if (list1.find(temp) == list1.end()) {									// check if element does not exist, insert if true 
			list1.insert(my_pair(temp,1));
			} else {
				list1[temp]++;														// if yes, increase its counter
			}
		}

		for (int i = 0; i < elementsInSecondList;++i) {
			cin >> temp;
			if (list2.find(temp) == list2.end()) {									// check if element does not exist, insert if true 
			list2.insert(my_pair(temp,1));
			} else {
				list2[temp]++;														// if yes, increase its counter
			}
		}

		int result = 0;

		auto e = list1.begin();
		while (e != list1.end() ) {
			if (list2.find(e->first) != list2.end()) {								// if both lists contain an element, add to result absolute value of the difference of the counter
				result += abs(e->second - list2[e->first]);
				e->second = 0;														// set both counters to 0
				list2[e->first] = 0;
     		} else if (list2.find(e->first) == list2.end()) {						// if another set does not contain this element
     			result += (e->second);												// add to the result its counter
     			e->second = 0;														// set counter to 0
     		}
			++e; 
		}
		
		e = list2.begin();
		while (e != list2.end() ) {
			if (list1.find(e->first) != list1.end()) {
				result += abs(e->second - list1[e->first]);
				e->second = 0;
				list1[e->first] = 0;
     		} else if (list1.find(e->first) == list1.end()) {
     			result += (e->second);
     			e->second = 0;
     		}
			++e; 
		}

			cout << result << endl;


			
}
	return 0;
		
}
