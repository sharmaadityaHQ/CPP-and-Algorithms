// https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/

// Given a set of numbers where all elements occur even number
// of times except one number, find the odd occurring number

int findOdd(int arr[], int n) {
    int res = 0, i;
    for(i=0; i<n; i++) {
        res ^= arr[i];
    }
    return res;
}