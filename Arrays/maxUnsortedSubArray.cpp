// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

// traverse array from start and find index where not sorted
// check if sorted, then return -1
// traverse array from end and find index where not sorted
// calculate max and min within the range
// traverse from 0 to start-1 to check for first element less than min
// traverse from n-1 to end+1 to check if element is less than max

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    vector<int> B;
    int s = 0, e = n-1;  
    for(s=0; s < n-1; s++) {
        if(A[s] > A[s+1]) {
            break;
        }
    }
    if(s == n-1) {
        B.push_back(-1);
        return B;
    }
    for(e = n-1; e > 0; e--) {
        if(A[e] < A[e-1]) {
            break;
        }
    }
    int max=A[s], min=A[s];
    for(int i=s+1; i<=e; i++) {
        if(A[i] < min) {
            min = A[i];
        }
        if(A[i] > max) {
            max = A[i];
        }
    }
    for(int i=0; i<s; i++) {
        if(A[i] > min) {
            s = i;
            break;
        }
    }
    for(int i=n-1; i>e; i--) {
        if(A[i] < max) {
              e = i;
              break;
        }
    }
    B.push_back(s);
    B.push_back(e);
    return B;
}

