// Variation of unbounded knapsack problem

// Input - int length[], int price[], int n (length of rod)
// Output - Max profit by cutting rod
// int t[size+1][length+1] where size = size of array and length = length of rod

int rodCutting(int length[], int price[], int n) {
    int t[n+1][n+1];

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < n+1; j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(length[i-1] <= j) {
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]], t[i-1][j]);
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][n];
}