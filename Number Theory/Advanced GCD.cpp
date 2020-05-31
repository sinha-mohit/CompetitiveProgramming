/*
Advanced GCD

Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm
int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}
and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
Input
The first line of the input file contains a number representing the number of lines to follow. Each line consists of two number A and B (0 <= A <= 40000 and A <= B < 10^250).
Output
Print for each pair (A,B) in the input one integer representing the GCD of A and B..
Sample Input:
2
2 6
10 11
Sample Output:
2
1

input: 
1
1000 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
output:
1000


input: 
4
45 178945612302145687
456587 102456888888888897844444444456
546 77777777777777788888888899999
455023 111111444444444555555555555666666667777777788888888
output:
1
1
3
1
*/


#include<iostream>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    if(a < b){
        return gcd(b, a);
    }
    else
        return gcd(b, a % b);
    
}
int main(){
	ll t;
    cin >> t;
    while(t--){
        ll a;
        string b;
        cin >> a >> b;
         if(a==0){
            cout<<b<<endl;
            continue;
        }
        ll res = 0;
        for(int i = 0; i < b.length(); i++){
            res = ((res * 10) + (b[i] - '0')) % a;
        }
        cout << gcd(a, res) << endl;
    }
	return 0;
}