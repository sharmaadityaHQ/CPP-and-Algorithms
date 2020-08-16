// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, i, x, y;
    set<int> s;
    set<int>::iterator pos;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> x >> y;
        if (x == 1)
        {
            s.insert(y);
        }
        else if (x == 2)
        {
            s.erase(y);
        }
        else
        {
            pos = s.find(y);
            if (pos != s.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}
