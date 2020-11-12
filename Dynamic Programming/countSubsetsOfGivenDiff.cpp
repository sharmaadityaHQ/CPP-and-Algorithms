// Input - int arr[], int n, int diff(Difference)
// Output - No. of subsets whose difference of sums is equal to given difference (diff)

// s1 - s2 = diff;
// s1 + s2 = sum;
// 2s1 = diff + sum;
// s1 = (diff + sum) / 2;

int countSubsetsOfGivenDiff(int arr[], int diff, int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    s1 = (diff + sum) / 2;
    
    int t[n+1][s1+1];

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < s1+1; j++) {
            if(i == 0) {
                t[i][j] = 0;
            }
            if(j == 0) {
                t[i][j] = 1;
            }
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < s1+1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][s1];
}