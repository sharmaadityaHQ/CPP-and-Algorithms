// https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    unordered_map<char, int> m;
    int count = 1;
    int solution = 0;
    for(char i = 'A'; i <= 'Z'; i++) {
        m.insert({i, count});
        count++;
    }
    for(int i = A.size() - 1,j = 0; i >= 0; i--) {
        solution += m[A[i]] * pow(26, j);
        j++;
    }
    return solution;
}
