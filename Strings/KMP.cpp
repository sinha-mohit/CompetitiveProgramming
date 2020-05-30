/*
String Search
Send Feedback
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
*/
#include <iostream>
#include <cstring>
using namespace std;
void computeLPS(char *pat, int m, int* lps) {
    int i = 0;
    int j = 1;
    lps[0] = 0;
    while (j < m) {
        if (pat[i] == pat[j]) {
            lps[j] = i + 1; // plus one karke dalrahe hai
            i += 1;
            j += 1;
        }
        else {
            if (i != 0) {
                i = lps[i - 1];
            }
            else {//if i == 0
                lps[j] = 0;
                j += 1;
            }
        }
    }
}
int findString(char *txt, char *pat) {
    int n = strlen(txt);
    int m = strlen(pat);
    //cout << n << ", " << m << endl;
    int* lps = new int[m];
    for (int i = 0; i < m; i++) {
        lps[i] = 0;
    }
    computeLPS(pat, m, lps); // longest proper prefix which is also a suffix (this is within pattern) 
    int i = 0;
    int j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i += 1;
            j += 1;
        }
        else {
            if (j != 0) {
                j = lps[j - 1]; // longest proper prefix which is also a suffix (this is betwenn text and pattern) 
            }
            else {
                i += 1; // if j == 0 then increment i because nothing matched at j = 0 i.e first character is not same
            }
        }


        if (j == m) {
            delete[] lps;
            return i - j; // return the starting index
        }
    }
    delete[] lps;
    return -1; //nothing matched

}
int main(){
    char text[] = "aacyaacybaacyaacyaax";
    char pattern[] = "acy";
    cout << findString(text, pattern) << endl;
    return 0;
}