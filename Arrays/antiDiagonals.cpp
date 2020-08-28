// https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> B;
    int row, col;
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[i].size(); j++) {
            vector<int> C;
            if(i == 0 || j == A.size() - 1) {
                int row = i, col = j;
                while(row < A.size() && col >= 0) {
                    C.push_back(A[row][col]);
                    row++;
                    col--;
                }
                B.push_back(C);
                C.clear();
            }
        }
    }
    return B;
}