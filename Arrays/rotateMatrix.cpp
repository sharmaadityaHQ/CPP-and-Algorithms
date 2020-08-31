// https://www.interviewbit.com/problems/rotate-matrix/

// Rotate array in form of squares dividing matrix into squares or circles
// to solve without extra space

void Solution::rotate(vector<vector<int> > &A) {
    int N = A.size();
    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 
            int temp = A[i][j]; 
            A[i][j] = A[N - 1 - j][i]; 
            A[N - 1 - j][i] = A[N - 1 - i][N - 1 - j]; 
            A[N - 1 - i][N - 1 - j] = A[j][N - 1 - i]; 
            A[j][N - 1 - i] = temp; 
        } 
    }
}
