/*
Multiplicative Inverse:
    A * B = 1
    A = B^-1

Multiplicative Modulo Inverse(A, B and m are integers)
    (A * B) % m = 1

    (5 * B) % 17 = 1
    then B = 7

Use Extended Euclid Algorithm to find B
    (A * B) % m = 1
    (A * B - 1) % m = 0
    the A * B - 1 is multiple of m
    (A * B - 1) = m * q (q is a integer)
    A * B - m * q = 1
    A * B + m * Q = 1   (Q = -q)

    ax + by = c (linear diophantine equation)
    solution will exits if gcd(a, b) divides c.
    hence if 
    gcd(A, m) divides 1 then only B exits
    Hence gcd(A, m) should be equal to 1 if B as a 
    integral solution needs to exits;

    if gcd(A, m) = 1;
    that is A and m is coPrime

    A * B + m * Q = gcd(A, m)   (Q = -q)
    if gcd(A, m) = 1;
*/
#include <iostream>
using namespace std;
struct node{
    int x;
    int y;
    int gcd;
};

node extendedEuclid(int a, int b){
    //Base Case
    if(b == 0){
        node ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    // if(a < b){
    //     return extendedEuclid(b, a);
    // } this is giving wrong ans

    //Extended Euclid Algorithm
    node smallAns = extendedEuclid(b, a % b);
    node ans;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    ans.gcd = smallAns.gcd;
    return ans;

}
int multiplicativeModuloInverse(int a, int m){
    node ans = extendedEuclid(a, m);
    return ans.x;
}
int main(){ //gcd(A, m) should be 1 so pass such values of A and m
    int A = 5;
    int m = 12;
    int B = multiplicativeModuloInverse(A, m);
    cout << "Multiplicative Modulo Inverse is: " << B << endl;
    return 0;
}
/*
    (A * B) % m = 1

    (5 * B) % 17 = 1
    then B = 7
*/ 

