#include <iostream>
#include <string>
using namespace std;
void buildZ(int *Z, string str){
    int l = 0;
    int r = 0;
    int len = str.length();
    Z[0] = 0; //since first index is of no use
    
    // the loop calculates Z[i] for i = 1 to len-1
    for(int i = 1; i < len; i++){
        if(i > r){
            /*matlab i does not between l and r that is Z value does 
            not exists for this ith character*/
            l = i;
            r = i;
            while(r < len && str[r - l] == str[r]){ /*str[r - l] is relative (original start of our str that is prefix comparision)*/
                r++;
            }
            Z[i] = r - l; /*not r - l + 1 because already r ek step aage hai*/
            r--;
        }
        else if(i <= r){
            /*i lies in the range l and r so some Z[i] calculations are already done*/
            int relIdx = i - l; /* gives relative starting indx for comparision*/
            if(Z[relIdx] <= r - i){ // or if(i + Z[relIdx] <= r)
                /* matlab the length of matched string (starting at ith) which is also
                a prefix, wo length is less than or equal to the left over length (r - i)*/
                /*len1 = (r - i) that is baccha hua range;
                  len2 = Z[relIdx] that is pehle hi matched hua string ka length
                  and then 
                  if len2 <= len1 then */
                Z[i] = Z[relIdx];
            }
            else if(Z[relIdx] > r - i){
                /*if it crosses the upper bound r matlab oor jaada string match hone ki 
                possibilities hai since len2 > len1*/
                //new range l and r aab banega

                l = i; //starting of new range
                while(r < len && str[r - l] == str[r]){
                    r++;
                }
                Z[i] = l - r;
                r--;
            }
        }
    }
}
void searchString(string text, string pattern){
    string tempString = pattern + "$" + text; //delimitter
    int * Z = new int[tempString.length()]();
    buildZ(Z, tempString);
    for(int i = 0; i < tempString.length(); i++){
        if(Z[i] == pattern.length()){
            cout << "Pattern is at index: " << i - (pattern.length() + 1) << endl; // +1 due to addition of delimitter
        }
    }
    delete[] Z;
}
int main(){
    string text = "aacyaacybaacyaacyaax";
    string pattern = "aacy";
    searchString(text, pattern);
    return 0;
}