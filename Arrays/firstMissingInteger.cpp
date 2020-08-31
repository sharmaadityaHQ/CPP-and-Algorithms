// https://www.interviewbit.com/problems/first-missing-integer/

// O(n) time and O(1) extra space solution

void sep(vector<int> &A)
{
    int j = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] <= 0) {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
            j++;
        }
    }
    A.erase(A.begin(), A.begin() + j);
}

int Solution::firstMissingPositive(vector<int> &A) {
    sep(A);
    int i;
    for(i=0;i<A.size();i++)
    {
        if(abs(A[i]) - 1 < A.size() && A[abs(A[i]) - 1] > 0) {
            A[abs(A[i]) - 1] = - A[abs(A[i]) - 1];
        }
    }
    for(i=0;i<A.size();i++)
    {
        if(A[i]>0)
            return i+1;
    }
    return A.size()+1;
}