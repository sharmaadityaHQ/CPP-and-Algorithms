// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, i, type, marks;
    string name;
    char space;
    map<string, int> m;
    map<string, int>::iterator pos;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> type >> name;
        if (type == 1)
        {
            cin >> marks;
            m[name] += marks;
        }
        else if (type == 2)
        {
            m.erase(name);
        }
        else
        {
            pos = m.find(name);
            if (pos != m.end())
            {
                cout << pos->second << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
}
