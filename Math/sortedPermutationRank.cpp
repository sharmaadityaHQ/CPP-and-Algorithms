// https://www.interviewbit.com/problems/sorted-permutation-rank/

int mod = 1000003;

int fact(int n) {
    return (n<=1)?1:(n*fact(n-1)) %mod;
}

int Solution::findRank(string A) {
    int rank=1;
    for(int i=0;i<A.size();i++){
        int c=0;
        for(int j=i+1;j<A.size();j++) {
            if(A[i]>A[j])c++;
        }
        rank=(rank+(c*fact(A.size()-1-i))%mod)%mod;
    }
    return rank;
}

