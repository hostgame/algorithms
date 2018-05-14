#include <bits/stdc++.h>
#include <map>

using namespace std;

struct comp {
    bool operator() (pair<string, int> i, pair<string, int> j)
    {
        return i.second > j.second;
    }
};

int main ()
{
    int n;      cin >> n;
    
    vector <pair<string, int>> s;
    for (int i = 0; i < n; i++)
    {
        string name; cin >> name;
        int total = 0;
        int temp;   cin >> temp;
        total += temp;
        cin >> temp;
        total += temp * 30;
        cin >> temp;
        total += temp * 365;
    
        s.emplace_back(name, total);
    }
    
    auto first = min_element(s.begin(), s.end(), comp());
    auto last = max_element(s.begin(), s.end(), comp());
    cout << first->first << endl;
    cout << last->first << endl;
    
    return 0;
}



