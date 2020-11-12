// Input - Array, Sum, Size of array
// Output - No. of subsets of given sum

int countOfSubsetSum(int arr[], int sum, int n) {
    int t[n+1][sum+1];

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < sum+1; j++) {
            if(i == 0) {
                t[i][j] = 0;
            }
            if(j == 0) {
                t[i][j] = 1;
            }
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}