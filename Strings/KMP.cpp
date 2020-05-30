// C++ program for implementation of KMP pattern searching algorithm 
// youtube: https://www.youtube.com/watch?v=4jY57Ehc14Y&t=2s
//#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
	// length of the previous longest matching proper prefix which is also a suffix 

	lps[0] = 0;       // lps[0] is always 0 
	int i = 1; 
	int j = 0; 


    /*   0 1 2 3 4 5 6
    pat: a a b a a a c
           i
         j
    j = 0; i = 1;
    lps[0] = 0;  
    */

	// the loop calculates lps[i] for i = 1 to M-1 
	while (i < M) { 
		if (pat[i] == pat[j]) { 
			lps[i] = j + 1; 
			j++;
			i++; 
		} 
		else // (pat[i] != pat[j]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (j != 0) { 
				j = lps[j - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (j == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	//int lps[M]; 
    int *lps = new int[M];

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("Found pattern at index %d \n", i - j); 
			j = lps[j - 1]; // again reset j = lps[j - 1] to find mutiple occurences in overlapping situations
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; /*j - 1 because present jth char match ni hua hai 
                and i which is index for txt[] is going to be same*/
			else{// if(j == 0)
				i = i + 1; 
                /*j is the index for pattern and here j is equal to zero.
                and if (pat[j] != txt[i]) that is pat[0] != txt[0] that is
                first character is not same between text and pattern, then just
                increment i or go to next char in text i.e increment i 
                          0 1 2 3 4 5
                eg: Text: a b c a b c
                              i 
                    patt: x y z
                          j
					then i++;
                */
            }
		} 
	} 
    delete[] lps;
} 


// Driver program to test above function 
int main() 
{ 
	char txt[] = "AABAACAADAABAABA"; 
	char pat[] = "AABA"; 
	KMPSearch(pat, txt); 
	return 0; 
} 
