/*
SUBXOR
Send Feedback
A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7   
Sample Output
3
*/
//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#define ll long long int

struct Node{
    ll lC,rC;
    Node *right, *left;
};

Node *getNode(){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->lC = temp->rC = 0;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(Node *root, ll n, ll level){
    if(level == -1){return;}
    
    if(n&(1<<level)){
        root->rC += 1;
        if(!root->right){
            root->right = getNode();
        }
        insert(root->right, n, level-1);
    }
    else{
        root->lC += 1;
        if(!root->left){
            root->left = getNode();
        }
        insert(root->left, n, level-1);
    }
    
    //return root;
}

ll query(Node *root, ll n, ll level, ll k){
    if(!root || level == -1){return 0;}
    
    bool p = (n&(1<<level));
    bool q = (k&(1<<level));
    
    if(q){
        if(!p){return root->lC+query(root->right, n, level-1, k);}
        else{return root->rC+query(root->left, n, level-1, k);}
    }
    else{
        if(!p){return query(root->left,n,level-1,k);}
        else{return query(root->right,n,level-1,k);}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll t, n, k, temp, ans, x;
    cin>>t;
    while(t--){
        ans = temp = x = 0;
        cin>>n>>k;
        Node *root = getNode();
        insert(root, x, 20);
        for(ll i = 0; i < n; i++){
            cin>>temp;
            x ^= temp;
            ans += query(root, x, 20, k); // pehle quesry karo fir ussko insert karo
            insert(root, x, 20);
        }
        cout<<ans<<endl;
    }
	return 0;
}