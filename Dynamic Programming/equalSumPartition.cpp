// Input - Array (int arr[]), Size of array (int n)
// Output - True/False (If array can be divided into partitions of equal sum)

bool subsetSum(int arr[], int sum, int n) {
    int t[n+1][sum+1];

    // Initialization
    
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < sum + 1; j++) {
            if(i == 0) {
                t[i][j] = false;
            }
            if(j == 0) {
                t[i][j] = true;
            }
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

bool equalSumPartition(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if(sum % 2 != 0) {
        return false;
    }
    else {
        return subsetSum(arr, sum / 2, n);
    }
}