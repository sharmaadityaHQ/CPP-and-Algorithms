// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A)
{
    int i, carry;
    vector<int> B;
    for (int i = A.size() - 1; i != -1; i--)
    {
        // Initialize carry and add 1 to the last element
        if (i == A.size() - 1)
        {
            carry = 0;
            A[i] = A[i] + 1;
        }
        // Add 0 and carry for all other elements
        if (i != A.size() - 1)
        {
            A[i] = A[i] + 0 + carry;
            carry = 0;
        }
        // Check value and set carry in a separate case
        if (A[i] > 9)
        {
            carry++;
            A[i] = 0;
        }
    }
    // If carry is 1 after the loop then insert 1 at the beginning
    if (carry != 0)
    {
        A.insert(A.begin(), 1);
    }
    // Check for leading 0's if any
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
