// https://www.interviewbit.com/problems/prime-numbers/

// If we cannot find a factor of a number till sqrt(n) then n is prime.
// This is because factors of a no exist in pairs.
// Time Complexity - O(nlog(logn)) (Inner loop - n/2 + n/3 + n/5 + n/7 + ...)

vector<int> Solution::sieve(int A) {
    vector<int> primes(A+1, 1);
    vector<int> B;
    primes[0] = 0;
    primes[1] = 0;
    for(int i = 2; i <= sqrt(A); i++) {
        if(primes[i] == 1) {
            for(int j = 2; i*j <= A; j++) {
                primes[i*j] = 0;
            }
        }
    }
    for(int i =0; i <= A; i++) {
        if(primes[i] == 1) {
            B.push_back(i);
        }
    }
    sort(B.begin(), B.end());
    return B;
}
