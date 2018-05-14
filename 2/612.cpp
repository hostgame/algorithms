#include <bits/stdc++.h>

using namespace std;

bool check (char a, char b)
{
    return a <= b;
};

int inv (string name)
{
    int total = 0;
    for (int i = 0; i < name.size(); i++)
    {
        for (int j = (i + 1); j < name.size(); j++)
        {
            if (i <= j and !check(name[i], name[j]))
                total++;
            else if (i >= j and check(name[i], name[j]))
                total ++;
        }
    }
    return total;
}

struct Dna {
    public:
    string name;
    int inversion;
    
    Dna(string aName)
    {
        name = aName;
        inversion = inv(name);
    };
};

struct comp {
    bool operator() (Dna a, Dna b)
    {
        return a.inversion < b.inversion;
    }
};

int main ()
{
    int number;     cin >> number;
    for (int i = 0; i < number; i++)
    {
        int length, rows; cin >> length;
        char ch; cin.get(ch);
        cin >> rows;
        vector <Dna> v;
        for (int j = 0; j < rows; j++)
        {
            string temp;    cin >> temp;
            v.emplace_back(Dna(temp));
        }
        
        stable_sort(v.begin(), v.end(), comp());
        
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j].name << endl;
        }
        
        if (i != number - 1)
            cout << endl;
    }
    return 0;
}



