// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

vector<int> computeLPSArray(string str) 
{ 
    int M = str.length(); 
    vector<int> lps(M); 
  
    int len = 0; 
    lps[0] = 0; // lps[0] is always 0 
    int i = 1; 

    while (i < M) 
    { 
        if (str[i] == str[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else
        { 
            if (len != 0) 
            { 
                len = lps[len-1]; 
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
    return lps; 
} 
  
// Method returns minimum character to be added at 
// front to make string palindrome 
int getMinCharToAddedToMakeStringPalin(string str) 
{ 
    string revStr = str; 
    reverse(revStr.begin(), revStr.end()); 
  
    // Get concatenation of string, special character 
    // and reverse string 
    string concat = str + "$" + revStr; 
  
    //  Get LPS array of this concatenated string 
    vector<int> lps = computeLPSArray(concat); 
  
    // By subtracting last entry of lps vector from 
    // string length, we will get our result 
    return (str.length() - lps.back()); 
} 

int Solution::solve(string A) {
    return getMinCharToAddedToMakeStringPalin(A);
}
