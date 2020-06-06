/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example:

Output:
Output the total unit of water trapped in between the blocks.

Constraints:
1 <= T <= 100
3 <= N <= 10^7
0 <= Ai <= 10^8

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of water trapped is 10 units.
*/

#include<iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return 0;
        }
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> ans(n, 0);
        
        left[0] = arr[0];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i - 1], arr[i]);
        }
        
        right[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(right[i + 1], arr[i]);
        }
        
        for(int i = 0; i < n; i++){
            ans[i] = min(left[i], right[i]) - arr[i];    
        }
        
        int area = 0;
        for(int i : ans){
            area += i;
        }
        return area;
    }
int main()
 {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> arr(n);
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
        cout << "Area: ";
	    cout << trap(arr) << endl;
	}
	return 0;
}