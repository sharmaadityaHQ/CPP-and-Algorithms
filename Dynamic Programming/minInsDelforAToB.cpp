// Minimum insertion and deletion to convert string A to string B

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

void minInsertAndDelete(string A, string B, int m, int n) {
    cout<<"Deletion "<<m - lcs(A, B, m, n);
    cout<<"Insertion "<<n - lcs(A, B, m, n);
}