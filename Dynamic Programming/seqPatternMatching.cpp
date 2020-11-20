// Input - string a, string b
// Output - Return true/false if a is a subsequence of b

int lcs(string X, string Y) {
    int m = X.size();
    int n = Y.size();
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

bool seqPatternMatching(string a, string b) {
    if(lcs(a, b) == a.size()) {
        return true;
    }
    else {
        return false;
    }
}