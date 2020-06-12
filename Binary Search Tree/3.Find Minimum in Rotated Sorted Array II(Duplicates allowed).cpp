/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/

#include <bits/stdc++.h>
using namespace std;


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

//Another Approach
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0;
        int r = num.size() - 1;
        int mid = 0;
        
        while(l < r) { //l == r pe break hoga 
            mid = l + (r - l) / 2;
            
            if (num[mid] > num[r]) {
                l = mid + 1;
            }
            else if (num[mid] < num[r]) {//sorted right half so ignore this half
                r = mid;
            }
            else { // when num[mid] and num[hi] are same
                r--;
            }
        }
        return num[l];
    }
};
/*When num[mid] == num[hi], we couldn't sure the position of minimum in mid's left or right, 
so just let upper bound reduce one.*/


//Another Approach
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0;
        int r = num.size() - 1;
        int mid = 0;
        while(r > 0 && num[0] == num[r]){
            --r;
        }
        int end_val = num[r];
        while(l < r) {
            mid = l + (r - l) / 2;
            
            if (num[mid] > end_val) {
                l = mid + 1;
            }
            else if (num[mid] <= end_val) {
                r = mid;
            }
        }
        return num[l];
    }
};

