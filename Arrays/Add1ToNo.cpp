// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A)
{
    int i, carry;
    vector<int> B;
    for (int i = A.size() - 1; i != -1; i--)
    {
        if (i == A.size() - 1)
        {
            carry = 0;
            A[i] = A[i] + 1;
        }
        if (i != A.size() - 1)
        {
            A[i] = A[i] + 0 + carry;
            carry = 0;
        }
        if (A[i] > 9)
        {
            carry++;
            A[i] = 0;
        }
    }
    if (carry != 0)
    {
        A.insert(A.begin(), 1);
    }
    int ind = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != 0)
        {
            ind = i;
            break;
        }
    }
    if (ind != -1 && A.size() != 1)
    {
        for (int i = 0; i < A.size() - ind; i++)
        {
            B.push_back(A[ind + i]);
        }
        return B;
    }
    else
    {
        return A;
    }
}
