// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < A.size(); i++)
    {
        max_ending_here = max_ending_here + A[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        // Adding a postive or negative value to a negative no would
        // further decrease the sum so reset it to 0 and start fresh
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
