/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 1018

Example:
Input: 
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9
*/

#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define ll long long
using namespace std;
void NSR(vector<ll>& arr, ll n, ll* rightArr){
        stack<pair<ll,ll>> s;
        for(ll i = n - 1; i >= 0; i--){
            if(s.size() == 0){
                s.push({arr[i], 1});
                rightArr[i] = 1;
            }
            else{
                if(arr[i] > s.top().first){
                    s.push({arr[i], 1});
                    rightArr[i] = 1;
                }
                else{
                    ll count = 0;
                    while(s.size() != 0 && arr[i] <= s.top().first){
                        count = count + s.top().second;
                        s.pop();
                    }
                    s.push({arr[i], count + 1});
                    rightArr[i] = count + 1;
                }
            }
        }
    }
    void NSL(vector<ll>& arr, ll n, ll* leftArr){
        stack<pair<ll,ll>> s;
        for(ll i = 0; i < n; i++){
            if(s.size() == 0){
                s.push({arr[i], 1});
                leftArr[i] = 1;
            }
            else{
                if(s.top().first < arr[i]){
                    s.push({arr[i], 1});
                    leftArr[i] = 1;
                }
                else{
                    ll count = 0;
                    while(s.size() != 0 && s.top().first >= arr[i]){
                        count += s.top().second;
                        s.pop();
                    }
                    s.push({arr[i], count + 1});
                    leftArr[i] = count + 1;
                }
            }
        }
    }
ll largestRectangleArea(vector<ll>& arr) {
        ll n = arr.size();
        ll *countGreaterElementsLeft = new ll[n];        
        ll *countGreaterElementsRight = new ll[n];
        NSL(arr, n, countGreaterElementsLeft);
        NSR(arr, n, countGreaterElementsRight);
        ll maxArea = 0;
        ll area;
        for(ll i = 0; i < n; i++){
            area = (countGreaterElementsLeft[i] + countGreaterElementsRight[i] - 1) * arr[i];
            maxArea = max(maxArea, area);
        }
        delete[] countGreaterElementsLeft;
        delete[] countGreaterElementsRight;
        return maxArea;
    }
int main()
 {
	ll t;
	cin >> t;
	while(t--){
	    ll n;
	    cin >> n;
	    vector<ll> arr(n, 0);
	    for(ll i = 0; i < n; i++){
	        cin >> arr[i];
	    }
        //cout << "ans: ";
	    cout << largestRectangleArea(arr) << endl;
	}
	return 0;
}