#include<iostream>
using namespace std;
//O(logn)
int gcd(int a,int b){
    if(!b) return a;
    if(a < b) return gcd(b, a);
    return gcd(b,a%b);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
