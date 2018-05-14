#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

char ch;

struct comp {
    bool operator() (pair<char, int> i, pair<char, int> j)
    {
        return i.second > j.second;
    }
};

struct pred {
    bool operator() (pair<char, int> i)
    {
        return i.first == ch;
    }
};

int main ()
{
    int number;     cin >> number;
    for (int i = 0; i < number; i++)
    {
        vector <pair<char, int>> s;
        int r, c, m, n;     cin >> r >> c >> m >> n;
        int counter = 0;
        for (int j = 0; j < r; j++)
        {
            string temp;    cin >> temp;
            for (int k = 0; k < c; k++)
            {
                counter++;
                ch = temp[k];
                auto it = find_if(s.begin(), s.end(), pred());
                if (it == s.end())
                    s.emplace_back(ch, 1);
                else
                    it->second++;
            }
        }
    
        sort(s.begin(), s.end(), comp());
        int imp = s.begin()->second;
        int mult = 1;
        for (auto it = s.begin() + 1; it != s.end(); it++)
        {
            if (it->second != imp)
                break;
            mult++;
        }
        imp *= mult;
        int total = imp * m + (counter - imp) * n;
        cout << "Case " << (i + 1) << ": " << total << endl;
    }
    return 0;
}



