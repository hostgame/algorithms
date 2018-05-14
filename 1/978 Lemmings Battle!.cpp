#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> my_pair;

void battle(int number_of_battlefields, multiset<int>& green, multiset<int>& blue) {

	vector<my_pair> v;

	for (int i = 0; i < number_of_battlefields; ++i) {
			
		auto G_end = green.end();					// multiset::end returns pointer to next after last element 
		G_end--;									// therefore we need to --it to get access to the last element
		
		auto B_end = blue.end();					// multiset::end returns pointer to next after last element 
		B_end--;									// therefore we need to --it to get access to the last element

		
		v.push_back( my_pair (*G_end,*B_end) );
		green.erase(G_end);
		blue.erase(B_end);
		
		if (green.size() == 0 || blue.size() == 0 )  {     // loop should be broken in case multisets contain different amount of values
			break;
		}

	}

	for (int i = 0; i < v.size() ;++i) {					// lemming battle
		if (v[i].first == v[i].second) {
			v[i].first = 0;
			v[i].second = 0;
		}

		if (v[i].first > v[i].second) {
			v[i].first = v[i].first - v[i].second;
			v[i].second = 0;
		}

		if (v[i].second > v[i].first) {
			v[i].second = v[i].second - v[i].first;
			v[i].first = 0;
		}
	}

	for (int i =0; i < v.size();++i) {					// we have to put lemmings back to the multiset to start next round
		if (v[i].first != 0) {
			green.insert(v[i].first);
		}
		if (v[i].second != 0) {
			blue.insert(v[i].second);
		}
	}

	if (green.size() == 0 || blue.size() == 0) {	  // battle ends if one of the armies gets completely destroyed
		return;
	}
	
	battle(number_of_battlefields,green,blue);							// call next round of the battle

}

int main() {
	int cases;
	cin >> cases;
	for (int q = 0; q < cases; ++q) {


	multiset<int> green;
	multiset<int> blue;

	int number_of_battlefields;

	int greens;
	int blues;
	int temp;
	cin >> number_of_battlefields >> greens >> blues;
	
	for (int i = 0; i < greens;++i) {
		cin >> temp;
		green.insert(temp);
	}

	for (int i = 0; i < blues;++i) {
		cin >> temp;
		blue.insert(temp);
	}

	battle(number_of_battlefields,green,blue);

	if (green.size() == 0 && blue.size() == 0) {
		cout << "green and blue died" << endl;
	}

	if (green.size() != 0) {
		cout << "green wins" << endl;
		auto it = green.end();
		it--;
		for (int i = 0; i < green.size();++i) {
			cout << *it << endl;
			it--;
		}
	}

	if (blue.size() != 0) {
		cout << "blue wins" << endl;
		auto it = blue.end();
		it--;
		for (int i = 0; i < blue.size();++i) {
			cout << *it << endl;
			it--;

		}
	}

	if (q != cases-1) {
	cout << endl;
	}
}
	return 0;
}