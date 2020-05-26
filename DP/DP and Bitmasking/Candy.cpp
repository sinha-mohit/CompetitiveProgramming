/*
Candy
Send Feedback
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6

Input:
4
1 0 1 1 
1 1 0 0 
0 0 1 1 
1 0 0 1

Output:
3
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define MAXN 16
long long dp[1<<16];

long long solver(vector <long long>& valid, long long n, long long student, long long mask){
    long long cnt = __builtin_popcountll(mask);
    if(cnt == n){
        return 1;
    }
    if(dp[mask] > -1){
        return dp[mask];
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        if((mask & (1 << i)) == 0 && (valid[student] & (1 << i)) >= 1){
            ans = ans + solver(valid, n, student + 1, (mask | (1 << i)));
        }
    }
    return dp[mask] = ans;
}
long long solve(int like[][MAXN],int n){
    vector <long long> valid;
    
    for(int i = 0; i < n; i++){
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(like[i][j] > 0){
                ans = ans + pow(2, n - j - 1);
            }
        }
        valid.push_back(ans);
    }
    memset(dp, -1, sizeof(dp));
    return solver(valid, n, 0, 0);
}

int main()
{
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout << solve(like,n) << endl;
}