// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<int> maxFromEnd(n+1, INT_MIN);
    for(int i = A.size() - 1; i >= 0; i--) {
        maxFromEnd[i] = max(maxFromEnd[i+1], A[i]);
    }
    int result = 0;
    for(int i = 0; i < A.size(); i++) {
        int low = i + 1, high = A.size() - 1, ans = i;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(A[i] <= maxFromEnd[mid]) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        result = max(result, ans - i);
    }
    return result;
}
