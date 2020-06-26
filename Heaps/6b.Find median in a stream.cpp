/*
https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in the stream. Then the next N lines contains integer x denoting the number to be inserted into the stream.
Output:
For each element added to the stream print the floor of the new median in a new line.
 
Constraints:
1 <= N <= 106
1 <= x <= 106
 
Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4
 
Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    /*"for inserting first two elements, insert bigger element in minHeap and smaller in maxHeap". 
    Ans: No need to insert the first 2 elements in this way, just set the median to zero in the beginning and 
    do everything as mentioned inside the loop.*/
    
    vector<double> res;
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    
    double median = 0;

    for (int i=0; i<a.size(); i++) {
        if (a[i] <= median) {
                maxheap.push(a[i]);
        } else {
                minheap.push(a[i]);
        }
    
        if (minheap.size() > maxheap.size()+1) {
                maxheap.push(minheap.top());
                minheap.pop();
        }
        if (maxheap.size() > minheap.size()+1) {
                minheap.push(maxheap.top());
                maxheap.pop();
        }
    
        if (minheap.size() == maxheap.size()) {
                median = (maxheap.top() + minheap.top())/2.0;
        } else if(minheap.size() > maxheap.size()) {
                median = (double)minheap.top();
        } else if (minheap.size() < maxheap.size()) {
                median = (double)maxheap.top();
        }
        
        res.push_back(median);
    }
    for(int x : res){
        cout << x << endl;
    }
    return 0;
}