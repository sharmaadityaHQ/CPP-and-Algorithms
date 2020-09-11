// https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string A) {
    int sign = 1, i = 0, base = 0;
    // skip leading whitespaces
    while(A[i] == ' ') {
        i++;
    }
    if(A[i] == '-') {
        sign = -1;
        i++;
    }
    else if(A[i] == '+') {
        sign = 1;
        i++;
    }
    while(A[i] >= '0' && A[i] <= '9') {
        // check overflow
        if(base > INT_MAX/10 || (base == INT_MAX/10 && A[i] - '0' > 7)) {
            if(sign == 1) {
                return INT_MAX;
            }
            else {
                return INT_MIN;
            }
        }
        base = (base * 10) + A[i++] - '0';
    }
    return base * sign;
}
