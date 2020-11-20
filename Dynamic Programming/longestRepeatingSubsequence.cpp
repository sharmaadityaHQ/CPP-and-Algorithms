// Input - string X, int m (size of string)
// Output - Length of longest repeating subsequence

int longestRepeatingSubsequence(string X, int m) {
    int t[m+1][m+1];
    string Y = X;

    for(int i = 0; i < m+1; i++) {
        for(int j = 0; j < m+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < m+1; i++) {
        for(int j = 1; j < m+1; j++) {
            if(X[i-1] == Y[j-1] && i != j) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }        
    }
}