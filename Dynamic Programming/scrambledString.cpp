https://leetcode.com/problems/scramble-string

// Recursion with Memoization

class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(string a, string b) {
        if(a == b) {
            return true;
        }
        if(a.length() <= 1) {
            return false;
        }
        string key = a;
        key.push_back(' ');
        key.append(b);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }
        int n = a.length();
        bool flag = false;
        for(int i = 1; i <= n-1; i++) {
            if((solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i))) || 
                (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i)))) {
                flag = true;
                break;
            } 
        }
        
        return mp[key] = flag;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) {
            return false;
        }
        if(s1.empty() && s2.empty()) {
            return true;
        }
        return solve(s1, s2);
    }
};