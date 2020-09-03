// https://www.interviewbit.com/problems/greatest-common-divisor/

// GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number.

int Solution::gcd(int A, int B) {
    if (B == 0) 
        return A; 
    return gcd(B, A % B);  
}

