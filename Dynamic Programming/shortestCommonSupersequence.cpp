// Length of shortest common supersequence

int lcs(string X, string Y, int m, int n) {
    int t[m+1][n+1];

    for(int i = 0; i < m+1; i++) {
        for(int j = 0; j < n+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < m+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(X[i-1] == Y[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }

    return t[m][n];
}

int shortestCommonSuperSequence(string X, string Y, int m, int n) {
    return m + n - lcs(X, Y, m, n);
}

// Print shortest common supersequence
// Similar to printing longest common subsequence

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int t[str1.size()+1][str2.size()+1];
        
        for(int i = 0; i < str1.size(); i++) {
            for(int j = 0; j < str2.size()+1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < str1.size()+1; i++) {
            for(int j = 1; j < str2.size()+1; j++) {
                if(str1[i-1] == str2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        
        int i = str1.size(), j = str2.size();
        
        string s = "";
        
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else {
                if(t[i][j-1] > t[i-1][j]) {
                    s.push_back(str2[j-1]);
                    j--;
                }
                else {
                    s.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        
        while(i > 0) {
            s.push_back(str1[i-1]);
            i--;
        }
        
        while(j > 0) {
            s.push_back(str2[j-1]);
            j--;
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};