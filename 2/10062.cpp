#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ch;
    string input;
    int counter = 0;
    while(getline(cin, input))
    {
        if (counter != 0)
            cout << endl;
        counter ++;
        int chars[128] = {0};
            vector<pair<int,int>> res;
         for(int i = 0; i < input.length(); i++)
            {
                ch = input[i];
                chars[ch]++;
            }
            
         for(int i = 0; i < 128; i++)
            {
                if(chars[i] != 0)
                {
                    pair<int, int> p(i, chars[i]);
                    res.push_back(p);
                }
                    
            }
            
            sort(res.begin(), res.end(), [](pair<int,int> p1, pair<int,int> p2){if(p1.second != p2.second) return p1.second < p2.second;
    return p1.first > p2.first;});
            
            for(int i = 0; i < res.size() ; i++)
            {
                cout << res[i].first << " " << res[i].second << endl;
            }   
            res.clear();
    }
    
}