#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int m;
	while (cin >> m and m){
		vector<long long> v(m);
		for (int i = 0; i < m; i++){
			cin >> v[i];
		}
		int max = 0;
		for (int i = 0; i < m; i++){
			for (int j = i + 1; j < m; j++){
				for (int k = j + 1; k < m; k++){
					long long sum = v[i] + v[j] + v[k];
					auto p = lower_bound(v.begin(), v.end(), sum);
					if (sum == v[p - v.begin()] and sum > max){
						max = sum;
					}
				}
			}
		}
		if (max == 0)
			cout << "no solution" << endl;
		else 
			cout << max << endl;
		
	}
	
	
	return 0;
}
