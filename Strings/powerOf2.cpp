// https://www.interviewbit.com/problems/power-of-2/

int Solution::power(string A) {
    int n = A.size(), num = 0, j = 0;
    if(A == "1" || A == "0") {
        return 0;
    }
    while(j != n-1) {
        num = 0;
        while(A[j] == '0') {
            j++;
        }
        if((A[n-1] - '0') % 2){
            return 0;
        }
        for(int i = j; i < n; i++) {
            num = num*10 + (A[i] - '0');
            A[i] = (num / 2) + '0';
            num = num % 2;
        }
    }
    return 1;
}
