/*
Palindromic Substrings
Send Feedback
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int countPalindromeSubstrings(char s[]) {
	int length = strlen(s);
    int count = 0;
    for(int i = 0; i < length; i++){
        
        //odd lenth palindrome
        int l = i;
        int r = i;
        while(l >= 0 && r < length && s[l] == s[r]){
            count++;
            l--;
            r++;
        }
        
          
        
        //even length palindrome
        l = i;
        r = i + 1;
        while(l >= 0 && r < length && s[l] == s[r]){
            count++;
            l--;
            r++;
        }
    }
    
    return count;
}
