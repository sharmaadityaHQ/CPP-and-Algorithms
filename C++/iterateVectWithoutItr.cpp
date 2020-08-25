#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 

	vector<int> arr = { 1, 2, 3, 4 }; 

	// Traversing the vector using 
	// values directly 
	for (auto it : arr) { 

		// Print the values 
		cout << it << ' '; 
	} 

    for (auto& it : arr) { 
        it *= 2; 
    } 

    for (auto& it : arr) { 
        cout << it << ' '; 
    } 
    
	return 0; 
} 