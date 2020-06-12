/*
Given a sorted array A of size N and a number X, you need to find the number of occurrences of X in A.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input: The first line contains N and X(element whose occurrence needs to be counted). The second line contains the elements of the array separated by spaces.

Output:
For each testcase, print the count of the occurrences of X in the array, if count is zero then print -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 103
1 <= X <= 103

Example:
Input:
2
7 2
1 1 2 2 2 2 3
7 4
1 1 2 2 2 2 3
Output:
4
-1

Explanation:
Testcase 1: 2 occurs 4 times in 1 1 2 2 2 2 3
Testcase 2: 4 is not present in 1 1 2 2 2 2 3
*/

#include <bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin >> t;
	while(t--){
	    int n, target;
	    cin >> n >> target;
	    int * arr = new int[n];
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    int start, mid, end, first, last;
	    start = 0;
	    end = n - 1;
	    first = -1;
	    last = -1;
	    
	    //first occurance
	    while(start <= end){
	        mid = start + (end - start) / 2;
	        if(arr[mid] == target){
	            first = mid;
	            end = mid - 1;
	        }
	        else{
	            if(target > arr[mid]){
	                start = mid + 1;
	            }
	            else{
	                end = mid - 1;
	            }
	        }
	    }
	    
	    //last occurance
	    start = 0;
	    end = n - 1;
	    while(start <= end){
	        mid = start + (end - start) / 2;
	        if(arr[mid] == target){
	            last = mid;
	            start = mid + 1;
	        }
	        else{
	            if(target > arr[mid]){
	                start = mid + 1;
	            }
	            else{
	                end = mid - 1;
	            }
	        }
	    }
	    if(first == -1 && last == -1){
	        cout << -1 << endl;
	    }
	    else{
	        cout << last - first + 1 << endl;
 	    }
 	    delete[] arr;
	}
	return 0;
}