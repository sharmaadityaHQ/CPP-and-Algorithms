// https://www.interviewbit.com/problems/roman-to-integer/

int Solution::romanToInt(string A) {
    unordered_map<char, int> m;
    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 500});
    m.insert({'M', 1000});
    int sum = 0;
    if(A.size() != 1) {
    for(int i = 0; i < A.size() - 1; i++) {
        if(m[A[i]] >= m[A[i+1]]) {
            sum += m[A[i]];
        }
        else {
            sum -= m[A[i]];
        }
        if(i == A.size() - 2) {
            sum += m[A[i+1]];
        }
    }
    return sum;
    }
    else {
        return m[A[0]];
    }
}
