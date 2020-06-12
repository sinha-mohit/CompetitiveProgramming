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

//Best Approach
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



//Another Approach (Another best Approach, first find min Index and then return the element at that min Index)
class Solution {
public:
    int pivotind(vector<int>& a, int st, int end, int n){
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
        {   // if(a[st] >= a[mid] && a[mid] >= a[end])
            // mid kabhi min indx hoga hi nahi, search in both half if not able to decide to select which half
            int res1=pivotind(a,mid+1,end,n);
            int res2=pivotind(a,st,mid-1,n);
            // if(res1==0)
            //     return res2;
            // return res1;            //index: 0 1 2 3 4 5 6 7 8 9
            return max(res1, res2);   //   num: 1 2 3 4 5 5 6 8 9 1    so this will return indx 9 and not indx 0 for min value in the array
        }
    }
    
    int findMin(vector<int>& nums) {
        int pivotIdx = pivotind(nums, 0, nums.size() - 1, nums.size());
        return nums[pivotIdx];
    }
};