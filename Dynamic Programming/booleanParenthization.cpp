// Input - String having boolean expression (T, F, |, ^, &)
// Output - No. of ways of placing brackets such that expression evaluates to true

#include<bits/stdc++.h>
using namespace std;

// Recursive 

int solve(string s, int i, int j, bool isTrue) {
    if(i > j) {
        return false;
    }

    if(i == j) {
        if(isTrue == true) {
            return s[i] == 'T';
        }
        else {
            return s[i] == 'F';
        }
    }

    int ans = 0;

    for(int k = i+1; k <= j-1; k+=2) {
        int lt = solve(s, i, k-1, true);
        int lf = solve(s, i, k-1, false);
        int rt = solve(s, k+1, j, true);
        int rf = solve(s, k+1, j, false);

        if(s[k] == '&') {
            if(isTrue == true) {
                ans = ans + lt*rt;
            }
            else {
                ans = ans + lt*rf + lf*rt + lf*rf;
            }
        }

        else if(s[k] == '|') {
            if(isTrue == true) {
                ans = ans + lt*rt + lt*rf + lf*rt;
            }
            else {
                ans = ans + lf*rf;
            }
        }

        else if(s[k] == '^') {
            if(isTrue == true) {
                ans = ans + lt*rf + lf*rt;
            }
            else {
                ans = ans + lf*rf + lt*rt;
            }
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout<< solve(s, 0, s.size()-1, true);
}
