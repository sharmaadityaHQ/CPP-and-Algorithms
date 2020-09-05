// https://www.interviewbit.com/problems/implement-strstr/

// B is sub-string, A is main string

int Solution::strStr(const string A, const string B) {
    int M = B.length(); 
    int N = A.length(); 
  
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        for (j = 0; j < M; j++) 
            if (A[i + j] != B[j]) 
                break; 
  
        if (j == M) 
            return i; 
    } 
  
    return -1; 
}
