/*
linear diophantine equation:
    integral solution of ax + by = c will exits only if 
    gcd(a, b) divides c.
    eg: 3x + 6y = 8 
    (integral solution does not exits since gcd(3, 6) = 3 that does not divides 8)
    eg: 2x + 3y = 6
    (integral solution exits since gcd(2, 3) = 1 that divides 6)
    x = 6, y = -2; 

*/
/*
Extended Euclid Algorithm:
    if ax + by = gcd(a, b)
    then find integers x and y.(integers x and y will exits since c = gcd(a, b) and gcd(a, b) divides c from above theorem)
    Now we find those x and y by using Extented Euclid Algorithm.

    Now ax + by = gcd(a, b) = gcd(b, a % b)
    let b*x1 + (a%b)*y1 = gcd(b, a % b) ......recursive call
    and a % b = a - b * floor(a / b)
    b*x1 + (a - b * floor(a / b))*y1 = gcd(b, a % b) = gcd(a, b) = ax + by
    
    Result: 
    x = y1
    y = x1 - floor(a / b)*y1
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
    /*
    ax + 0*y = gcd(a, 0) = a
    ax = a;
    x = 1;
    */
    if(b == 0){
        node ans;
        ans.x = 1;
        ans.y = 0;//let y = 0
        ans.gcd = a;
        return ans;
    }

    // if(a < b){
    //     return extendedEuclid(b, a);
    // } this is giving wrong ans

    //Extended Euclid Algorithm
    node smallAns = extendedEuclid(b, a % b);
    node ans;
    ans.x = smallAns.y; //x = y1
    ans.y = smallAns.x - (a / b) * smallAns.y; //y = x1 - floor(a / b)*y1
    ans.gcd = smallAns.gcd;
    return ans;

}

int main(){
    int a =15, b = 10;
    node ans = extendedEuclid(a, b);
    cout << "a: " << a << endl << "b: " << b << endl;
    cout << "x: " << ans.x << endl;
    cout << "y: " << ans.y << endl;
    cout << "gcd(a, b): " << ans.gcd << endl;
    return 0;
}

/*
15x + 10y = gcd(15, 10) = 5
15x + 10y = 5

15(1) + 10(-1) = 5
*/