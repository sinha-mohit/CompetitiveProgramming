/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        //finding the min element index which is the pivot
        while(left < right){ //left == right pe break hoga everytime(modified binary search)
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        int pivotIdx = left;
        
        left = 0;
        right = nums.size() - 1;
        //deciding to search for target in left side of pivot or in right size of pivot (since no duplicates so you can do this)
        if(target <= nums[right]){
            left = pivotIdx;
        }
        else if(target >= nums[left]){
            right = pivotIdx - 1;
        }
        else{
            return -1;
        }
        
        //then find the element(normal Binary Search)
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else{
                if(target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;//if not present
    }
};