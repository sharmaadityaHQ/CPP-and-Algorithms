// https://www.interviewbit.com/problems/rearrange-array/

// An array element is needed that can store two different values at the same time.
// To achieve this every element at ith index is incremented by (A[A[i]] % n)*n.
// After the increment operation of first step,
// every element holds both old values and new values. Old value can be obtained by
// A[i]%n and a new value can be obtained by A[i]/n.

// Time - O(n), Space - O(1)

void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for (int i=0; i < n; i++) 
        A[i] += (A[A[i]]%n)*n; 
  
    for (int i=0; i<n; i++) 
        A[i] /= n; 
}
