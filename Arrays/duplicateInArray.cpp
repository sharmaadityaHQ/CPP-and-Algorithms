https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size() - 1;
    int sq = sqrt(n); 
    int range = (n / sq) + 1; 
    int count[range] = {0}; 
  
    // Dividing the array in blocks of size root n and updating count of elements
    for (int i = 0; i <= n; i++) 
    { 
        count[(A[i] - 1) / sq]++; 
    } 
  
    // select last block as default block
    int selected_block = range - 1; 
    for (int i = 0; i < range - 1; i++) 
    { 
        if (count[i] > sq) 
        { 
            selected_block = i; 
            break; 
        } 
    } 
    unordered_map<int, int> m; 
    for (int i = 0; i <= n; i++) 
    { 
        if ( ((selected_block * sq) < A[i]) && 
                (A[i] <= ((selected_block + 1) * sq))) 
        { 
            m[A[i]]++; 
            if (m[A[i]] > 1) 
                return A[i]; 
        } 
    } 
  
    return -1; 

}
