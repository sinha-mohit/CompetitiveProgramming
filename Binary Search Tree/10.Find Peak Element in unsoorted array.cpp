/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
or index number 5 where the peak element is 6.

Follow up: Your solution should be in logarithmic complexity.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        if(n == 1){
            return 0;
        }
        if(nums[l] > nums[l + 1]){
            return l;
        }
        if(nums[r] > nums[r - 1]){
            return r;
        }
        int mid;
        while(l <= r){
            mid = l + (r -l) / 2;
            if(mid - 1 >= 0 and mid + 1 <= n and nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(mid - 1 >= 0 and nums[mid] > nums[mid - 1]){
                l = mid; //not mid - 1 as mid can be possible peak idx
            }
            else if(mid + 1 <= n and nums[mid] > nums[mid + 1]){
                r = mid; //not mid + 1 as mid can be possible peak idx
            }
            else{
                if(mid - 1 >= 0 and nums[mid] < nums[mid - 1]){
                    r = mid - 1;
                }
                else if(mid + 1 <= n and nums[mid] < nums[mid + 1]){
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};