/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while (l <= r) 
        {
            while (l < r && nums[l] == nums[l + 1]) l++; // skip duplicates from the left
            while (r > l && nums[r] == nums[r - 1]) r--; // skip duplicates from the right
            
            int mid = l + (r - l) / 2;
            
            if (target == nums[mid])
                return true;
            
            // there exists rotation; the middle element is in the left part of the PIVOT
            if (nums[mid] > nums[r]) 
            {
                if (target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // there exists rotation; the middle element is in the right part of the PIVOT
            else if (nums[l] > nums[mid]) 
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            // there is no rotation; just like normal binary search (sorted array)
            else 
            {
                if (target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};
