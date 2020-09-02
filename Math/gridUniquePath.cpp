// https://www.interviewbit.com/problems/grid-unique-paths/

// We have to take m + n - 2 steps in total. You have to take (m - 1) steps
// going down and (n-1) steps going right.

// Let 0 denote a down step and 1 denote a right step.

// We need to find out the number of strings of length m + n - 2 which
// have exactly m - 1 zeroes and n - 1 ones.
// So, the answer becomes Choose(m+n-2, n - 1).

int Solution::uniquePaths(int A, int B) {
    int m = A;
    int n = B;
    int path = 1; 
    for(int i = n; i < m+n-1; i++) {
        path *= i;
        path /= i-n+1;
    }
    return path; 
}
