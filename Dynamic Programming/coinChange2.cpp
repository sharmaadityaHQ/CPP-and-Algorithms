// Input - int coin[], int n(size of coin array), int sum
// Output - Min. no of coins required to make that sum

int coinChange(int coin[], int sum, int n) {
    int t[n+1][sum+1];

    // Initialization of first row and first coloumn

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < sum+1; j++) {
            if(j == 0) {
                t[i][j] = 0;
            }
            if(i == 0) {
                t[i][j] = INT_MAX - 1;
            }
        }
    }

    // Initialization of second row 

    for(int j = 1; j < sum+1; j++) {
        if(j % coin[0] != 0) {
            t[i][j] = INT_MAX - 1;
        }
        else {
            t[i][j] = j / coin[0];
        }
    }

    for(int i = 2; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            if(coin[i-1] <= j) {
                t[i][j] = min(1 + t[i][j-coin[i-1]], t[i-1][j]);
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    if(t[n][sum] != INT_MAX - 1) {
        return t[n][sum];
    }
    else {
        return -1;
    }
}