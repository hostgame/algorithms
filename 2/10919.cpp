#include <bits/stdc++.h>
#include <set>

using namespace std;

int main ()
{
    while (true)
    {
        int n, m;       cin >> n;
        if (n == 0)
            break;
        cin >> m;
        
        set <int> s;
        for (int i = 0; i < n; i++)
        {
            int temp;   cin >> temp;
            s.insert(temp);
        }
        
        bool check = true;
        for (int i = 0; i < m; i++)
        {
            int number, req;    cin >> number >> req;
            int counter = 0;
            for (int j = 0; j < number; j++)
            {
                int temp;   cin >> temp;
                if (s.find(temp) != s.end())
                    counter++;
            }
            if (counter < req)
                check = false;
        }
        
        if (check)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    
    return 0;
}



