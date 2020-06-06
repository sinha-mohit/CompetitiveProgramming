/*
215. Kth Largest Element in an Array
Medium
https://leetcode.com/problems/kth-largest-element-in-an-array/

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

input: [3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6]
20

output: 2
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minH;
        for(int i = 0; i < k; i++){
            minH.push(nums[i]);
        }
        int top = minH.top();
        int n = nums.size();
        for(int i = k; i < n; i++){
            if(nums[i] >= minH.top()){
                minH.push(nums[i]);
                minH.pop();
            }
        }
        cout << minH.size();
        return minH.top();
    }
};
