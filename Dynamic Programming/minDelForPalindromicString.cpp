// Minimum deletion from a string to get a palindromic string
// Minimum insertion in a string to make it a palindromic string

int lcs(string X, string Y) {
    int t[X.size()+1][Y.size()+1];

    for(int i = 0; i < X.size()+1; i++) {
        for(int j = 0; j < Y.size()+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < X.size()+1; i++)
    {
        for (int j = 1; j < Y.size()+1; j++)
        {
            if(X[i-1] == Y[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }

    return t[X.size()][Y.size()];
}

int minDelforPalindromicString(string X) {
    string Y = X;
    reverse(Y.begin(), Y.end());
    return X.length() - lcs(X, Y);
}