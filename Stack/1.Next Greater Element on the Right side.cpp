/*
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.

** For More Input/Output Examples Use 'Expected Output' option **
*/

//#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include<iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector <ll> v;
		stack <ll> s;
		vector <ll> arr(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = n - 1; i >= 0; i--) {
			if (s.size() == 0) {
				v.push_back(-1);
				s.push(arr[i]);
			}
			else {
				if (s.top() > arr[i]) {
					v.push_back(s.top());
					s.push(arr[i]);
				}
				else {
					while (s.size() != 0 && s.top() <= arr[i]) {
						s.pop();
					}
                    //important step because while loop can break because of two reasons..
					if (s.size() == 0) { //if stack is empty
						v.push_back(-1);
						s.push(arr[i]);
					}
					else { //if s.top > arr[i]
						v.push_back(s.top());
						s.push(arr[i]);
					}
					
				}
			}
		}

		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;

	}
	return 0;
}