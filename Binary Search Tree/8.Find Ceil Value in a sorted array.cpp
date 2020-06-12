/*
    Ceiling in a sorted array
Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, 
and the floor is the greatest element smaller than or equal to x. 
Assume than the array is sorted in non-decreasing order. 
Write efficient functions to find floor and ceiling of x.


Examples :

For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    floor doesn't exist in array,  ceil  = 1, idx = 0
For x = 1:    floor  = 1,  ceil  = 1, idx = 0
For x = 5:    floor  = 2,  ceil  = 8, idx = 2
For x = 20:   floor  = 19,  ceil doesn't exist in array, idx = -1

Input:
4
7 0
1 2 8 10 10 12 19
7 1
1 2 8 10 10 12 19
7 5
1 2 8 10 10 12 19
7 20
1 2 8 10 10 12 19

Output:
0
0
2
-1
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solver(ll *arr, ll n, ll x){
    int idx = -1;
	int l = 0, r = n - 1, m;
    while(l <= r){
	    m = l + (r - l) / 2;
	    if(arr[m] == x){
	        return m;
	    }
        else if(arr[m] > x){
            idx = m;
	        r = m - 1;
        }
        else if(arr[m] < x){
            l = m + 1;
        }
    }
    return idx;
}
int main()
 {
	int t;
	cin >> t;
	while(t--){
	    ll n, x;
	    cin >> n >> x;
	    ll *arr = new ll[n];
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
        cout << "Ceil value idx: ";
	    cout << solver(arr, n, x) << endl; 
	    delete[] arr;
	}
	return 0;
}