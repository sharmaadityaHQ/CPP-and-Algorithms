// Input - Array or String (int arr[]), int n (Size of array)
// Min cost of multiplication of matrices (Min no of multiplications)

// Recursive

int solve(int arr[], int i, int j) {
    if(i >= j) {
        return 0;
    }

    int minimum = INT_MAX;

    for(int k = i; k <= j-1; k++) {
        int tempans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        if(tempans < minimum) {
            minimum = tempans;
        }
    }

    return minimum;
}

int main() {
    solve(arr, 1, n-1);
}

// Memoized

int t[1001][1001]; // From constraints

memset(t, -1, sizeof(t));

int solve(int arr[], int i, int j) {
    if(i >= j) {
        return 0;
    }

    int minimum = INT_MAX;

    if(t[i][j] != -1) {
        return t[i][j];
    }

    for(int k = i; k <= j-1; k++) {
        int tempans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        if(tempans < minimum) {
            minimum = tempans;
        }
    }

    return t[i][j] = minimum;
}

int main() {
    solve(arr, 1, n-1);
}