// Input - string X, string Y, int n, int m (n, m are size of strings)
// Output - Length of longest common subsequence

// Recursive approach

int lcs(string X, string Y, int n, int m) {
    if(n == 0 || m == 0) {
        return 0;
    }
    if(X[n-1] == Y[m-1]) {
        return 1 + lcs(X, Y, n-1, m-1);
    }
    else {
        return max(lcs(X, Y, n, m-1), lcs(X, Y, n-1, m));
    }
}

// Memoization

int t[n+1][m+1];
memset(t, -1, sizeof(t));
int lcs(string X, string Y, int m, int n) {
    if(n == 0 || m == 0) {
        return 0;
    } 
    if(t[m][n] != -1) {
        return t[m][n];
    }
    if(X[m-1] == Y[n-1]) {
        return t[m][n] = 1 + lcs(X, Y, m-1, n-1);
    }
    else {
        return t[m][n] = max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
    }
}

// Tabulation

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

// Print longest common subsequence

void printLcs(string X, string Y, int m, int n) {
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

    int i = m, j = n;
    string s = "";

    while(i > 0 && j > 0) {
        if(X[i-1] == Y[j-1]) {
            s.push_back(X[i-1]);
            i--;
            j--;
        }
        else {
            if(t[i][j-1] > t[i-1][j]) {
                j--;
            }
            else {
                i--;
            }
        }
    }

    reverse(s.begin(), s.end());

    cout<<s;
}