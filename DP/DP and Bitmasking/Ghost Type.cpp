/*
Ghost Type
Send Feedback
Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N
.

A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N
.

Constraints:
1 ≤ N ≤ 20

SAMPLE INPUT
4

SAMPLE OUTPUT
8

Explanation
All the special permutations of length 4 are: 1 2 3 4

1 2 4 3

1 4 2 3

2 1 3 4

2 1 4 3

2 4 1 3

4 1 2 3

4 2 1 3

*/
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

#define ll long long

ll solver(ll mask, vector<ll> submask[], ll n, ll* dp) {
	//cout<<mask<<endl;
	if (mask == ((1 << (n + 1)) - 2)) {
		return 1;
	}

	if (dp[mask] != -1) {
		return dp[mask];
	}



	ll ans = 0;
	for (ll i = n; i >= 1; i--) {
		if ((mask & (1 << i)) == 0) {
			ll ok = 1;
			for (ll j = submask[i].size() - 1; j >= 0; j--) {
				ll x = submask[i][j];
				if ((mask & (1 << x)) == 0) {
					//cout<<"YES"<<endl;
					ok = 0;
					break;
				}
			}

			if (ok) {
				ans += solver((mask | (1 << i)), submask, n, dp);
			}
		}
	}

	dp[mask] = ans;
	//cout<<ans<<endl;
	return ans;
}

int main() {
	ll n;
	cin >> n;
	//vector<ll> submask[n + 1];
	vector<ll>* submask = new vector<ll>[n + 1];
	for (ll i = 1; i <= n; i++) {
		for (ll j = i - 1; j > 0; j--) {
			if ((j & i) == j) {
				submask[i].push_back(j);
			}
		}

	}

	ll* dp = new ll[1 << (n + 2)];

	for (ll i = 0; i < (1 << (n + 2)); i++) {
		dp[i] = -1;
	}
	ll mask = 0;
	ll ans = solver(mask, submask, n, dp);

	cout << ans << endl;
	delete[] dp;
	delete[] submask;

	return 0;
}