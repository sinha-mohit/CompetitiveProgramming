/*
Given a non-empty array of integers, return the k most frequent elements.
https://leetcode.com/problems/top-k-frequent-elements/
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/
#include <bits/stdc++.h>
using namespace std;

struct comp{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2){
        if(p1.second == p2.second){
            return p1.first > p2.first;// if frequencies of two elements are same 
            // then the larger number should come first 
        }
        return p1.second < p2.second;// insert elements in the priority queue on the basis of 
        // decreasing order of frequencies (maxHeap)
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(int x : nums){
            um[x]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> maxH(um.begin(), um.end());
        
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(maxH.top().first);
            maxH.pop();
        }
        return ans;
    }
};