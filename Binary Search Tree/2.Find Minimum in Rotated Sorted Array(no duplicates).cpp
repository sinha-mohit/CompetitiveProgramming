/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0){
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        //finding the min element index
        while(left < right){ //left == right pe break hoga everytime(modified binary search)
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }
};


//Another Approach (works for duplicate elements too)
class Solution {
public:
    int findMini(vector<int>& nums, int l, int r){
        //one or two element, sort it directly
        if(l + 1 >= r){
            return min(nums[l], nums[r]);
        }
        //if range is already sorted
        if(nums[l] < nums[r]){
            return nums[l];
        }
        //else recursively find the solution
        int mid = l + (r - l) / 2;
        return min(findMini(nums, l, mid), findMini(nums, mid + 1, r));
    }
    
    int findMin(vector<int>& nums) {
        return findMini(nums, 0, nums.size() - 1);
    }
};