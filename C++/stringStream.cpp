// stringstream ss("23,4,56");
// char ch;
// int a, b, c;
// ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    stringstream parse(str);
    char ch;
    int a;
    vector<int> arr;
    while (parse >> a)
    {
        parse >> ch;
        arr.push_back(a);
    }
    return arr;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << endl;
    }
    return 0;
}