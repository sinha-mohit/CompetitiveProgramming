/*
https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0
https://www.youtube.com/watch?v=2JSQIhPcHQg&t=2061s

You are given N number of books. Every ith book has Pi number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations, and print this minimum value. 
Each book will be allocated to exactly one student. Each student has to be allocated atleast one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better understanding).

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:Each case begins with a single positive integer N denoting the number of books.The second line contains N space separated positive integers denoting the pages of each book.And the third line contains another integer M, denoting the number of students.

Output:
For each test case, output a single line containing minimum number of pages each student has to read for corresponding test case.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A [ i ] <= 106
1 <= M <= 106

Example:
Input:
2
4
12 34 67 90
2
3
15 17 20
2
Output:
113
32

Explaination:
Testcase 1:Allocation can be done in following ways:
{12} and {34, 67, 90}     Maximum Pages = 191
{12, 34} and {67, 90}     Maximum Pages = 157
{12, 34, 67} and {90}        Maximum Pages = 113

Therefore, the minimum of these cases is 113, which is selected as output.

Testcase 2: Allocation can be done in following ways:
{15} and {17, 20} Maximum pages = 37
{15, 17} and {20} Maximum Pages = 32

So, the output will be 32.
*/


/*
Good example: 
1
8
250 74 159 181 23 45 129 174
6 

ans: 250

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isValid(ll *arr, ll n, ll mid, ll k){
    ll cnt = 1;
    ll sum = 0; //sum can be long long
    for(int i = 0; i < n; i++){
        if((sum + arr[i]) <= mid){
            sum += arr[i];
        }
        else{
            cnt++;
            sum = 0;
            sum += arr[i];
        }
    }
    return cnt <= k ? true : false;
}
int main()
 {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    ll *arr = new ll[n];
	    ll sum = 0;
	    ll maxi = 0;
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	        sum += arr[i];
	        maxi = max(maxi, arr[i]);
	    }
	    ll k, m;
	    cin >> k;
	    if(k > n){
	        cout << -1 << endl;
	        continue;
	    }
	    ll l = maxi, r = sum, ans = -1; // left l = maxi and r = sum of pages, l = max of array, imp set because max in array, koi ek student ko minimum no. of max pages padhna hi padega at minimum
        //see the good exmple:
        //if you put l = 0 then ans is 233 which is not possible
	    while(l <= r){
	        m = l + (r - l) / 2;
	        if(isValid(arr, n, m, k)){
	            ans = m;
	            r = m - 1;
	        }
	        else{
	            l = m + 1;
	        }
	    }
	    cout << ans << endl;
	    delete[] arr;
	}
	return 0;
}