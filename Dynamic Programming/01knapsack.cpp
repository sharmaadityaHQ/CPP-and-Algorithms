// 0-1 Knapsack problem

// Input - weights (int wt[]), values (int val[]), capacity of knapsack (int W), Size of array (int n)
// Output - maximum profit (int)

// Recursive approach

int knapsack(int wt[], int val[], int W, int n) {
    if(n == 0 || w == 0) {
        return 0;
    }
    if(wt[n-1] <= W) {
        return max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1), knapsack(wt, val, W, n-1));
    }
    else if(wt[n-1] > W) {
        return knapsack(wt, val, W, n-1);
    }
}

// Memoization (Recursive call + storage in matrix)

// Create matrix (int t[n+1][w+1]) with variables that are changing (n, w), size of matrix from constraints given in question
// Initialize the matrix with -1

int t[102][1002];
memset(t, -1, sizeof(t));
int knapsack(int wt[], int val[], int W, int n) {
    if(n == 0 || w == 0) {
        return 0;
    }
    if(t[n][w] != -1) {
        return t[n][w];
    }
    if(wt[n-1] <= W) {
        return t[n][w] = max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1), knapsack(wt, val, W, n-1));
    }
    else if(wt[n-1] > W) {
        return t[n][w] = knapsack(wt, val, W, n-1);
    }
}

// Tabulation (Eliminates recursive calls, only matrix)

void knapsack(int wt[], int val[], int w, int n) {
    int t[n+1][w+1];

    // Initializaton of matrix (same as base condition in recursion)
    
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<w+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<w+1; j++) {
            if(wt[i-1] <= j) {
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    } 
}
