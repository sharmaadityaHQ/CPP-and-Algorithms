// Find the length of the longest palindromic subsequence

int lcs(string a, string b) {
    int t[a.size()+1][b.size()+1];
        
    for(int i = 0; i < a.size()+1; i++) {
        for(int j = 0; j < b.size()+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }
        
    for(int i = 1; i < a.size()+1; i++) {
        for(int j = 1; j < b.size()+1; j++) {
            if(a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
        
    return t[a.size()][b.size()];        
}
    
int longestPalindromeSubseq(string s) {
    string b = s;
    reverse(b.begin(), b.end());
    return lcs(s, b);        
}    