// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

// Every pair has one element which has set bit at ith position 
// and second element having unset bit at ith position contributes
// exactly 1 to sum, therefore total permutation count 
// will be count*(n-count) multiplied by 2 

int Solution::hammingDistance(const vector<int> &A) {
    long long int ans=0,n=A.size();
    long long int count;
    for(int i=0; i < 31; i++) {
        count = 0;
        for(int j=0; j<n; j++) {
            if(A[j] & 1<<i) {
                count++;
            }
        }
        ans = (ans + (count * (n-count) * 2));
    }
    return ans % 1000000007;
}

