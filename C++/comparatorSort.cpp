#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
};

bool comparatorFunction(Interval I1, Interval I2)
{
    return (I1.start < I2.start);
}

int main()
{
    Interval arr[] = {{6, 8}, {3, 5}, {2, 7}};
    sort(arr, arr + 3, comparatorFunction);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i].start << " " << arr[i].end << endl;
    }
}