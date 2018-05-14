#include <bits/stdc++.h>
using namespace std;

int main() {
		int n; 
		while (cin >> n) {
			if (n == 0) {
				return 0;
			}

			map<set<int>,int> v;
		
			for (int i = 0; i < n;++i) {
					int temp;
					set<int> t;								// we want our combinations of courses to be sorted before we put it to the map
					for (int j =0; j < 5;++j) {				// so we put it to set	
						cin >> temp;
						t.insert(temp);
					}
					
					if (v.find(t) == v.end()) {					// if set does not contain new combination, we insert it
						v.insert(pair<set<int>,int>(t,1));
					} else {									// if it does, we increase its counter 
						v[t]++;
					}
			}
		
			int max = 0;
			int max_popularity=0;

			for(auto it = v.begin(); it!=v.end(); it++){		
				if (max_popularity < (it->second)) {				// if we find more popular combination, than currently most popular combination
					max_popularity=it->second;						// assign value of popularity 
					max=0;											// reset maximum to 0
				}
				if (max_popularity==it->second) {					// if we have combination with the same popularity
					max+=max_popularity;							// sum them
				}
		    }	

		    cout << max << endl;
		}
	
	return 0;
}