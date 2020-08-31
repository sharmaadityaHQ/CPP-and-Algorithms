// https://www.interviewbit.com/problems/verify-prime/

int Solution::isPrime(int A) {
    int prime = 1;
    if(A != 1) {
        for(int i=2; i<=sqrt(A); i++) {
            if(A % i == 0) {
                prime = 0;
                break;
            }
        }
    }
    else {
        prime = 0;
    }
    return prime;
}
