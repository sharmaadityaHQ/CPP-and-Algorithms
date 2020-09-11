// Different ways to use std::string::append() in C++

string str1, str2;

// Appends str2 in str1
str1.append(str2);

// Appends 5 characters from 0th index of str2 to str1
str1.append(str2, 0, 5); 

// Appends "GeeksforGeeks" in str1
str1.append("GeeksforGeeks"); 

// Appends first 5 characters from "GeeksforGeeks" to str1
str1.append("GeeksforGeeks", 5);

// Appends 10 occurrences of '$' to str1
str1.append(10, '$'); 

// Appends all characters of the range [beg, end)
str1.append(str2.begin() + 5, str2.end());