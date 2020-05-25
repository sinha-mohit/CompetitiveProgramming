/*
       j1 j2 j3 j4 (job)
  p1:  10, 2, 6, 5
  p2:  1, 15, 12, 8
  p3:  7,  8,  9, 3
  p4:  15, 13, 4, 10

one person can do only one job and no two person can do samme job
minimise the total cost;

ans: 2 + 1 + 3 + 4 = 10

*/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int minCost(int cost[4][4], int n, int p, int mask, int *dp){
    if(p >= n){
        return 0;
    }
    if(dp[mask] != INT_MAX){
        return dp[mask];
    }
    int minimum = INT_MAX;
    for(int j = 0; j < n; j++){
        if((mask & (1 << j)) == 0){
            int ans = cost[p][n - j - 1] + minCost(cost, n, p + 1, mask | (1 << j), dp);
            minimum = min(minimum, ans);
        }
    }
    return dp[mask] = minimum;
}
int main(){
    int cost[4][4] = {{10, 2, 6, 5}, {1, 15, 12, 8}, {7, 8, 9, 3}, {15, 13, 4, 10}};
    int *dp = new int[1 << 4]; //dp size is 0 to 2^n - 1 so size = (1 << n)
    for(int i = 0; i < (1 << 4); i++){
        dp[i] = INT_MAX;
    }
    cout << minCost(cost, 4, 0, 0, dp) << endl;
    cout << dp[0] << endl; //final ans is also stored at dp[0];
    delete[] dp;
    return 0;
}