/*
Maximum XOR Subarray
Send Feedback
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/


#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

class trieNode{
    public:
        trieNode *left;
        trieNode *right;
};
void insert(ll num, trieNode *head){
    //assume 64 bits represents a number
    trieNode *current = head;
    for(ll i = 63; i >= 0; --i){
        //now how to get the i th bit??
        ll bit = (num >> i) & 1LL; //right the num by i times then and it with 1
        if(bit == 0){
            if(current->left == NULL){
                current->left = new trieNode();
                current->left->left = current->left->right = NULL;
                current = current->left;
            }
            else if(current->left != NULL){
                current = current->left;
            }
        }
        else if(bit == 1){
            if(current->right == NULL){
                current->right = new trieNode();
                current->right->left = current->right->right = NULL;
                current = current->right;
            }
            else if(current->right != NULL){
                current = current->right;
            }
        }
    }
}

ll query(ll curr_xor, trieNode *head){
    ll max_xor = 0;
    trieNode *curr = head;
    for(ll j = 63; j >= 0 ; --j){
        ll bit = (curr_xor >> j) & 1LL;
        if(bit == 0){ //move opposite side i.e., right
            if(curr->right != NULL){
                //max_xor = max_xor + (ll)pow(2,j);
                max_xor = max_xor + (1LL<<j);
                curr = curr->right;
            }
            else if(curr->right == NULL){
                curr = curr->left;
            }
        }
        else if(bit == 1){//move opposite side i.e., left
            if(curr->left != NULL){
                //max_xor = max_xor + (ll)pow(2,j);
                max_xor = max_xor + (1LL<<j);
                curr = curr->left;
            }
            else if(curr->left == NULL){
                curr = curr->right;
            }
        }
    }
    return max_xor;
}

int main(){
    ll n;
    cin >> n;
    ll *arr = new ll[n];
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
    }
    trieNode *head = new trieNode();
    head->left = head->right = NULL;
    
    ll max_xor = LONG_MIN;
    ll curr_xor = 0;
    insert(curr_xor, head);//insert 0 initially in the tire
    for(ll i = 0; i < n; ++i){
        curr_xor ^= arr[i]; 
        insert(curr_xor, head);
        ll ans = query(curr_xor, head);
        max_xor = max(max_xor, ans);
    }
    
	delete[] arr;
    cout << max_xor << endl;
    return 0;
}