// Input - string s
// Output - Minimum no of partition required such that every substring of the partition is a palindrome

// Recursive

bool isPalindrome(string s, int i, int j) {
    for(int a = i, b = j; a < b; a++, b--) {
        if(s[a] != s[b]) {
            return false;
        }
    }
        
    return true;
}

int palindromePartitioning(string s, int i, int j) {
    if(i >= j) {
        return 0;
    }
    if(isPalindrome(s, i, j)) {
        return 0;
    }
    int ans = INT_MAX;
    for(int k = i; k <= j-1; k++) {
        int temp = 1 + palindromePartitioning(s, i, k) + palindromePartitioning(s, k+1, j);
        if(temp < ans) {
            ans = temp;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    return palindromePartitioning(s, 0, s.size()-1);
}

// Memoization with Optimization

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        for(int a = i, b = j; a < b; a++, b--) {
            if(s[a] != s[b]) {
                return false;
            }
        }
        
        return true;
    }
    int t[2001][2001];
    int helper(string s, int i, int j) {
        if(i >= j) {
            return 0;
        }
        if(t[i][j] != -1) {
            return t[i][j];
        }
        if(isPalindrome(s, i, j)) {
            return 0;
        }
        int ans = INT_MAX;
        for(int k=i; k <= j-1; k++) {
            int left, right;
            if(t[i][k] != -1) {
                left = t[i][k];
            }
            else {
                left = helper(s, i, k);
                t[i][k] = left;
            }
            if(t[k+1][j] != -1) {
                right = t[k+1][j];
            }
            else {
                right = helper(s, k+1, j);
                t[k+1][j] = right;
            }
            int temp = 1 + left + right;
            if(temp < ans) {
                ans = temp;
            }
        }
        
        return t[i][j] = ans;
    }
    int minCut(string s) {
        memset(t, -1, sizeof(t));
        return helper(s, 0, s.size()-1);
    }
};