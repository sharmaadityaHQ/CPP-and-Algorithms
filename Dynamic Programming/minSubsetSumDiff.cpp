// Input - int arr[], int n
// Output - Min. difference of 2 partitions of the array

#include<bits/stdc++.h>
using namespace std;

void subsetSum(int arr[], int sum, int n) {
    int t[n+1][sum+1];

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < sum+1; j++) {
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
}

int minSubsetSumDiff(int arr[], int n) {
    int range = 0;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        range += arr[i];
    }
    subsetSum(arr, range, n);
    for(int i = 0; i <= range/2; i++) {
        if(t[n][i] == true) {
            v.push_back(i);
        }
    }
    return range - 2*v[v.size()-1];
}