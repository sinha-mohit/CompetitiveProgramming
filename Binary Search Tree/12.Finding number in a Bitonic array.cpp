/*
https://practice.geeksforgeeks.org/problems/finding-number/0
An array is called Bitonic if it is comprises of an increasing sequence of integers followed immediately by a decreasing sequence of integers.
Given a bitonic array A of N distinct integers. Find a element X in it.

Input:
First line will consist  a number T, the number of test cases. First line of each test case will consist of positive integer N. Next line contains array elements and third line contains X.

Output:
Print the index where element found. If element not found, print "-1" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 107
-107 <= Ai <= 107

Example:
Input:
1
5
1 2 7 4 3
2
Output:
1

Explanation:
Testcase 1: 2 is found at index 1 in the given array.
*/

#include <bits/stdc++.h>
using namespace std;
int FindMaxIdx(int *arr, int n){
    int l = 0, r = n - 1, m;
    while(l <= r){
        m = l + (r - l) / 2;
        if(m - 1 >= 0 && m + 1 <= n && arr[m] > arr[m + 1] && arr[m] > arr[m - 1]){
            return m;
        }
        else if(m + 1 <= n and arr[m] < arr[m + 1]){
            l = m + 1;
        }
        else if(m - 1 >= 0 and arr[m] < arr[m - 1]){
            r = m - 1;
        }
    }
    return n - 1;
}
int BSearchL(int *arr, int n, int l, int r, int x){
    //sorted ascending order
    int m;
    while(l <= r){
        m = l + (r - l) / 2;
        if(arr[m] == x){
            return m;
        }
        else if(arr[m] > x){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return -1;
}
int BSearchR(int *arr, int n, int l, int r, int x){
    //sorted decreasing order
    int m;
    while(l <= r){
        m = l + (r - l) / 2;
        if(arr[m] == x){
            return m;
        }
        else if(arr[m] > x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return -1;
}
int main()
 {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int *arr = new int[n];
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    int x;
	    cin >> x;
	    int maxIdx = FindMaxIdx(arr, n);
	    int ansL = BSearchL(arr, n, 0, maxIdx + 1, x);
	    int ansR = BSearchR(arr, n, maxIdx, n - 1, x);
	    if(ansL != -1){
	        cout << ansL << endl;
	    }
	    else{
	        cout << ansR << endl;
	    }
	    delete[] arr;
	}
	return 0;
}