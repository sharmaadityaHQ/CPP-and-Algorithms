// https://www.interviewbit.com/problems/set-matrix-zeros/

// First check row 1 and col 1 and then rest of the matrix.
// If any element in the rest of the matrix is 0 then make 1st element
// of that row and col as 0. Then check if 1st element of a row or
// col is 0 then make that complete row and col as 0

void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    int r1=0, c1=0;
    for(int i=0; i<n; i++) {
        if(A[0][i] == 0) {
            r1=1;
            break;
        }
    }
    for(int i=0; i<m; i++) {
        if(A[i][0] == 0) {
            c1 = 1;
            break;
        }
    }
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(A[i][j] == 0) {
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(A[0][j] == 0 || A[i][0] == 0) {
                A[i][j] = 0;
            }
        }
    }
    if(r1 == 1) {
        for(int i=0; i<n; i++) {
            A[0][i] = 0;
        }
    }
    if(c1 == 1) {
        for(int i=0; i<m; i++) {
            A[i][0] = 0;
        }
    }
}
