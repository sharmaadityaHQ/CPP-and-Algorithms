// https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int A) {
    char str[50]; 
    int i = 0;

    while (A > 0) { 
        int rem = A % 26; 

        // If remainder is 0, then a 'Z' must be there in output 
        if (rem == 0) { 
            str[i++] = 'Z'; 
            A = (A / 26) - 1; 
        } 
        else // If remainder is non-zero 
        { 
            str[i++] = (rem - 1) + 'A'; 
            A = A / 26; 
        } 
    } 
    str[i] = '\0'; 

    reverse(str, str + strlen(str)); 
    return str;
}
