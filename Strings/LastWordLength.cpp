// https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A) {
    int count = 0; 
    bool flag = false; 
    for (int i = A.length() - 1; i >= 0; i--) { 
        if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z')) { 
            flag = true; 
            count++; 
        } 
        else { 
            if (flag == true) 
                return count; 
        } 
    } 
    return count; 
}
