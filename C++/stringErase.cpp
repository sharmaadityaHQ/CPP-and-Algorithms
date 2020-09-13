// Different ways to use std::string::erase() in C++

// Deletes all characters 
str.erase();

// Deletes all characters starting from index 2
str.erase(2);

// Deletes 4 characters from index number 1 
str.erase(1, 4);

// deletes character at 4th index
str.erase(str.begin() + 4);

// Erases all characters of the range [beg, end)
str.erase(str.begin() + 0, str.end() - 6); 