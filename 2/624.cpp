#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v, r, a;
int maxSum, curSum;

void solve(int index){
	if (curSum <= n and curSum > maxSum){
		maxSum = curSum;
		a = r;
	}
	if (index == m){
		return;
	}
	
	solve(index + 1);
	curSum += v[index];
	r.push_back(v[index]);
	
	solve(index + 1);
	curSum -= v[index];
	r.pop_back();
}

int main(){
	while (cin >> n){
		cin >> m;
		v.resize(m);
		for (int i = 0; i < m; i++){
			cin >> v[i];
		}
		
		a.clear();
		curSum = 0;
		maxSum = 0;
		
		solve(0);
		
		for (int e: a){
			cout << e << ' ';
		}
		cout << "sum:" << maxSum << endl;
		
		
	}
	
	return 0;
}
