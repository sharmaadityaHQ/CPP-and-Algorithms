#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[2][3] = {0};
    int(*p)[3] = a;
    cout << a[0] << endl;
    cout << *a << endl;
    cout << a << endl;
    cout << &a[0][0] << endl;
    cout << p << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
    }
}