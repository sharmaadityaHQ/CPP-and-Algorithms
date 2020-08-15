// https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <bits/stdc++.h>
using namespace std;

int customSearch(vector<int> &arr, int num)
{
    int first = 0, last = arr.size() - 1, mid, found = 0;
    while (first <= last && found == 0)
    {
        mid = (first + last) / 2;
        if (arr[mid] == num && (mid == 0 || num > arr[mid - 1]))
        {
            found = 1;
            break;
        }
        if (num > arr[mid])
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    if (found == 0)
    {
        return found;
    }
    else
    {
        return mid + 1;
    }
}

int main()
{
    int n, i, q, result;
    cin >> n;
    vector<int> a(n);
    vector<int>::iterator pos;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    vector<int> number(q);
    for (i = 0; i < q; i++)
    {
        cin >> number[i];
    }
    for (i = 0; i < q; i++)
    {
        result = customSearch(a, number[i]);
        if (result == 0)
        {
            pos = lower_bound(a.begin(), a.end(), number[i]);
            cout << "No " << pos - a.begin() + 1 << endl;
        }
        else
        {
            cout << "Yes " << result << endl;
        }
    }
}