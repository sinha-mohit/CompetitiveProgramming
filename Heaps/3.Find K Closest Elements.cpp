/*
Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 10^4
Absolute value of elements in the array and x will not exceed 10^4
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        pair<int, int> rel;
        priority_queue<pair<int, int>> maxH; // automatically heapying on the basis of first element of the pair by default
        int n = arr.size();
        for(int i = 0; i < k; i++){ //push first k elements in the heap
            maxH.push({abs(arr[i] - x), arr[i]});
        }
        for(int i = k; i < n; i++){
            if(abs(arr[i] - x) < maxH.top().first){
                maxH.push({abs(arr[i] - x), arr[i]});
                maxH.pop();
            }
        }
        vector<int> ans;
        while(maxH.size() != 0){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
