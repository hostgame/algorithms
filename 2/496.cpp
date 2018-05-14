#include <bits/stdc++.h>

using namespace std;

int digits (int n)
{
    int number_of_digits;
    do {
         ++number_of_digits; 
         n /= 10;
    } while (n);
    return number_of_digits;
}
int main ()
{
    string linea;
    string lineb;
    while(getline(cin, linea))
    {
        getline(cin, lineb);
        vector <int> a;
        vector <int> b;
        
        istringstream sinpa (linea);
        istringstream sinpb (lineb);
        
        int temp;
        while (sinpa >> temp)
            a.push_back(temp);
        while (sinpb >> temp)
            b.push_back(temp);
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int sizea = a.size();
        int sizeb = b.size();

        vector <int> c; 
        vector <int> d;
        c = a;
        d = b;

        
        for (int i = 0; i < sizea; i++)
        {
            if (binary_search(d.begin(), d.end(), a[i]))
                d.erase(remove(d.begin(), d.end(), a[i]), d.end());
        }
        for (int i = 0; i < sizeb; i++)
        {
            if (binary_search(c.begin(), c.end(), b[i]))
                c.erase(remove(c.begin(), c.end(), b[i]), c.end());
        }
        
        if (c.size() == 0 and d.size() == 0)
            cout << "A equals B" << endl;
        else if (c.size() == 0)
            cout << "A is a proper subset of B" << endl;
        else if (d.size() == 0)
            cout << "B is a proper subset of A" << endl;
        else if (c.size() == sizea and d.size() == sizeb)
            cout << "A and B are disjoint" << endl;
        else cout << "I'm confused!" << endl;
        
    }
    return 0;
}



