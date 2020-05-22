/*
Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
struct node{
    int maxSum;
    int sum;
    int bestPreffixSum;
    int bestSuffixSum;
};

void buildTree(int *arr, node *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode].maxSum = arr[start];
        tree[treeNode].sum = arr[start];
        tree[treeNode].bestPreffixSum = arr[start];
        tree[treeNode].bestSuffixSum = arr[start];        
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode].maxSum = max({tree[2 * treeNode].maxSum, tree[2 * treeNode + 1].maxSum, tree[2 * treeNode].sum + tree[2 * treeNode + 1].bestPreffixSum, 
    tree[2 * treeNode + 1].sum + tree[2 * treeNode].bestSuffixSum, tree[2 * treeNode].bestSuffixSum + tree[2 * treeNode + 1].bestPreffixSum});
    
    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;

    tree[treeNode].bestPreffixSum = max(tree[2 * treeNode].bestPreffixSum, tree[2 * treeNode].sum + tree[2 * treeNode + 1].bestPreffixSum);

    tree[treeNode].bestSuffixSum = max(tree[2 * treeNode + 1].bestSuffixSum, tree[2 * treeNode + 1].sum + tree[2 * treeNode].bestSuffixSum);

    return;
}

node query(int *arr, node *tree, int left, int right, int start, int end, int treeNode){
    if(right < start || left > end){
        node z;
        z.maxSum = -16000; // important step
        z.sum = -16000;
        z.bestPreffixSum = -16000;
        z.bestSuffixSum = -16000;
        return z;
    }
    if(left <= start && end <= right){
        return tree[treeNode];
    }
    else{
        int mid = (start + end) / 2;

        node ansLeft = query(arr, tree, left, right, start, mid, 2 * treeNode);
        node ansRight = query(arr, tree, left, right, mid + 1, end, 2 * treeNode + 1);

        node z;

        z.maxSum = max({ansLeft.maxSum, ansRight.maxSum, ansLeft.sum + ansRight.bestPreffixSum, 
        ansRight.sum + ansLeft.bestSuffixSum, ansLeft.bestSuffixSum + ansRight.bestPreffixSum});


        z.sum = ansLeft.sum + ansRight.sum;

        z.bestPreffixSum = max(ansLeft.bestPreffixSum, ansLeft.sum + ansRight.bestPreffixSum);

        z.bestSuffixSum = max(ansRight.bestSuffixSum, ansRight.sum + ansLeft.bestSuffixSum);

        return z;
    }
    
}
int main(){
    int n;
    cin >> n;
    int *arr = new int[n+1];
    node *tree = new node[4 * n];
    for(int i = 1; i <=n; i++){
        cin >> arr[i];
    }
    buildTree(arr, tree, 1, n, 1);
    int q;
    cin >> q;
    while(q--){
        int left, right;
        cin >> left >> right;
        node z;
        z = query(arr, tree, left, right, 1, n, 1);
        cout << z.maxSum << endl;
    }
    delete[] arr;
    delete[] tree;
    return 0;
}