// https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> pascal (A);
    for (int line = 0; line < A; line++) 
    { 
        for (int i = 0; i <= line; i++)  
        { 
            pascal[line].push_back(1);
        } 
    } 
    for (int line = 1; line < A; line++) 
    { 
        int C = 1; 
        for (int i = 1; i <= line; i++)  
        { 
            pascal[line][i] = C * (line - i + 1) / i; 
            C = pascal[line][i];
        } 
    } 
    return pascal;
}
