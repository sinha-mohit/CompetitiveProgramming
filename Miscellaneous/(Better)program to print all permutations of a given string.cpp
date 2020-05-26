/*
Method 2 (using next_permutation)
We can use next_permutation that modifies a string so that it stores lexicographically next permutation. 
If current string is lexicographically largest, i.e., “CBA”, then next_permutation returns false.

We first sort the string, so that it is converted to lexicographically smallest permutation. 
Then we one by one call next_permutation until it returns false.
*/

#include <iostream>
#include <algorithm>
using namespace std; 

// using next_permutation 
void permute(string str) 
{ 
	// Sort the string in lexicographically 
	// ascennding order 
	sort(str.begin(), str.end()); 

	// Keep printing next permutation while there 
	// is next permutation 
	do { 
	cout << str << endl; 
	} while (next_permutation(str.begin(), str.end())); 
} 

// Driver code 
int main() 
{ 
	string str = "abcd"; 
	permute(str); 
	return 0; 
} 
//Note: Note that the second method always prints permutations in lexicographically sorted order irrespective of input string.
//also you can do this with arrays vectors too!