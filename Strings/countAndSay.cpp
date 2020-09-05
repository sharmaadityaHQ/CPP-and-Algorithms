// https://www.interviewbit.com/problems/count-and-say/

string Solution::countAndSay(int A) {
    int n = A;
    
    if(n == 1) {
        return "1";
    }
    
    if(n == 2) {
        return "11";
    }
    
    string str = "11";
    
    for(int i=3; i<=n; i++) {
        str+="$";
        string tmp = "";
        int len = str.length();
        int count = 1;
        for(int j=1; j<len; j++) {
            if(str[j] != str[j-1]) {
                tmp += count + '0';
                tmp += str[j-1];
                count = 1;
            }
            else {
                count++;
            }
        }
        str = tmp;
    }
    return str;
}
