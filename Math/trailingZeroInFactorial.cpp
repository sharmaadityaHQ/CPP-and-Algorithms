// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

int Solution::trailingZeroes(int A) {
    int count = 0; 
    for (int i = 5; A / i >= 1; i *= 5) 
        count += A / i; 
  
    return count; 
}