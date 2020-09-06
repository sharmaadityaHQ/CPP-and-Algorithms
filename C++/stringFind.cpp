// https://www.geeksforgeeks.org/string-find-in-cpp/

#include <iostream> 
#include <string> 
  
using namespace std; 
  
int main() 
{ 
    string str = "geeksforgeeks a computer science"; 
    string str1 = "geeks"; 
  
    // Find first occurrence of "geeks" 
    // Syntax 1
    // if the sub-string is not found it returns string::npos
    // string::npos is static member with value as the highest
    // possible for the size_t data structure

    size_t found = str.find(str1); 
    if (found != string::npos) 
        cout << "First occurrence is " << found << endl; 
  
    // Find next occurrence of "geeks". Note here we pass 
    // "geeks" as C style string. 
    // Syntax 2

    char arr[] = "geeks"; 
    found = str.find(arr, found+1); 
    if (found != string::npos) 
        cout << "Next occurrence is " << found << endl; 
  
    return 0; 
} 

// Output
// First occurrence is 0
// Next occurrence is 8