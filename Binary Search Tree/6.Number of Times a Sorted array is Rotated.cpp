/*
https://practice.geeksforgeeks.org/problems/rotation/0

Given a sorted array A of size N. The array is rotated 'K' times. Find the value of 'K'. The array may contain duplicate elements.

Input:
The first line contains an integer T, depicting total number of test cases. T testcases follow. Each testcase contains two lines of input. The first line contains an integer N depicting the size of array. The next line contains elements of the array separated by spaces.

Output:
For each testcase, print the value of K.

Constraints:
1 <= T <= 100
1 <= N <=107
0 <= Ai <= 1018

Example:    
Input
2
5
5 1 2 3 4
5
1 2 3 4 5
Output
1
0

Explanation:
Testcase1: 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.
*/


/*good input (where duplicates are allowed): when ambiguous, you have to check both sides
2
5
2 1 2 2 2
5
2 2 2 1 2

output: 
1
3
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int pivotind(ll a[],int st,int end,int n)
{
    if(st > end){
        return 0;
    }
    
    int mid=(st+end)/2;
    
    if(mid+1 < n && a[mid+1] < a[mid])
        return mid+1;
        
    if(mid-1 >= 0 && a[mid] < a[mid-1])
        return mid;
        
    if(a[st] < a[mid])
        return pivotind(a,mid+1,end,n);
        
    else if(a[mid] < a[end])
        return pivotind(a,st,mid-1,n);
        
    else
        { // if(a[st] >= a[mid] && a[mid] >= a[end])
            // mid kabhi min indx hoga hi nahi, search in both half if not able to decide
            int res1=pivotind(a,mid+1,end,n);
            int res2=pivotind(a,st,mid-1,n);
            // if(res1==0)
            //     return res2;
            // return res1;
            return max(res1, res2);
        }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        cout << pivotind(a,0,n-1,n) << endl;
    }
	return 0;
}