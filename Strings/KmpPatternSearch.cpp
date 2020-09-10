// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

#include <bits/stdc++.h> 
  
void computeLPSArray(char* pat, int M, int* lps); 
  
// Prints occurrences of pat[] in txt[] 
// lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]

void KMPSearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 
  
    int i = 0;
    int j = 0;

    while(i < N) {
        if(pat[j] == txt[i]) {
            i++;
            j++;
        }
        if(j == M) {
            cout<<"Pattern found at "<< i - j;
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if(i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
            if(j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
} 
  
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray (char *pat, int M, int *lps) {
    int len = 0; 
    lps[0] = 0; // lps[0] is always 0  
    int i = 1; 

    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else
        { 
            if (len != 0) { 
                len = lps[len - 1];
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
  
// Driver program to test above function 
int main() 
{ 
    char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB"; 
    KMPSearch(pat, txt); 
    return 0; 
} 